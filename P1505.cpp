#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> fri[200005];
pair<int, int> edge[200005];
int a[200005];
int fa[200005];
int dfn[200005];
int nowdfn;
int cnt[200005];
int son[200005];
int top[200005];
int dep[200005];
int m;
struct SEG{
    int num[3][800005];
    bool lt[800005];
    void pu(int now, int op) {
        if(op == 0) num[op][now] = num[op][now * 2] + num[op][now * 2 + 1];
        else if(op == 1) num[op][now] = max(num[op][now * 2], num[op][now * 2 + 1]);
        else num[op][now] = min(num[op][now * 2], num[op][now * 2 + 1]);
    }
    void pu(int now) {pu(now, 0), pu(now, 1), pu(now, 2);}
    void dorev(int now) {
        lt[now] ^= 1;
        num[0][now] = -num[0][now];
        int tmp = num[1][now];
        num[1][now] = -num[2][now];
        num[2][now] = -tmp;
    }
    void pd(int now, int nl, int nr) {
        if(!lt[now]) return;
        dorev(now * 2);
        dorev(now * 2 + 1);
        lt[now] = 0;
    }
    void edit(int now, int nl, int nr, int l, int nn) {
        if(l < nl || l > nr) return;
        if(nl == nr) {
            num[0][now] = nn, num[1][now] = nn, num[2][now] = nn;
            return;
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        edit(now * 2, nl, nmid, l, nn);
        edit(now * 2 + 1, nmid + 1, nr, l, nn);
        pu(now);
    }
    void rev(int now, int nl, int nr, int l, int r) {
        if(nr < l || nl > r) return;
        if(l <= nl && nr <= r) {
            dorev(now);
            return;
        }
        pd(now, nl, nr);
        int nmid = (nl + nr) >> 1;
        rev(now * 2, nl, nmid, l, r);
        rev(now * 2 + 1, nmid + 1, nr, l, r);
        pu(now);
    }
    int query(int now, int nl, int nr, int l, int r, int op) {
        if(nr < l || nl > r) return (op==2)?INT_MAX:((op==1)?INT_MIN:0);
        if(l <= nl && nr <= r) {
            return num[op][now];
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        if(op == 0) return query(now * 2, nl, nmid, l, r, op) + query(now * 2 + 1, nmid + 1, nr, l, r, op);
        else if(op == 1) return max(query(now * 2, nl, nmid, l, r, op), query(now * 2 + 1, nmid + 1, nr, l, r, op));
        else return min(query(now * 2, nl, nmid, l, r, op), query(now * 2 + 1, nmid + 1, nr, l, r, op));
    }
}seg;
void dfs1(int now, int from) {
    cnt[now] = 1;
    for(pair<int, int> i : fri[now]) {
        if(i.second == from) continue;
        a[i.second] = i.first; // 边权转点权
        fa[i.second] = now;
        dep[i.second] = dep[now] + 1;
        dfs1(i.second, now);
        cnt[now] += cnt[i.second];
        if(cnt[i.second] > cnt[son[now]]) son[now] = i.second;
    }
}
void dfs2(int now, int from) {
    dfn[now] = ++nowdfn;
    seg.edit(1, 1, n, nowdfn, a[now]);
    top[now] = from;
    if(son[now]) dfs2(son[now], from);
    for(pair<int, int> i : fri[now]) {
        if(i.second == son[now] || i.second == fa[now]) continue;
        dfs2(i.second, i.second);
    }
}
void rev(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        seg.rev(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(dfn[v] + 1 <= dfn[u])
        seg.rev(1, 1, n, dfn[v] + 1, dfn[u]);
}
int f(int u, int v, int op) {
    int ans = 0;
    if(op == 1) ans = INT_MIN;
    if(op == 2) ans = INT_MAX;
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        if(op == 0) ans += seg.query(1, 1, n, dfn[top[u]], dfn[u], 0);
        else if(op == 1) ans = max(ans, seg.query(1, 1, n, dfn[top[u]], dfn[u], 1));
        else ans = min(ans, seg.query(1, 1, n, dfn[top[u]], dfn[u], 2));
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(dfn[v] + 1 <= dfn[u]) {
        if(op == 0) ans += seg.query(1, 1, n, dfn[v] + 1, dfn[u], 0);
        else if(op == 1) ans = max(ans, seg.query(1, 1, n, dfn[v] + 1, dfn[u], 1));
        else ans = min(ans, seg.query(1, 1, n, dfn[v] + 1, dfn[u], 2));
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for(int i = 1, u, v, w; i < n; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        u++, v++;
        fri[u].push_back({w, v});
        fri[v].push_back({w, u});
        edge[i] = {u, v};
    }
    dfs1(1, 0);
    dfs2(1, 1);
    scanf("%d", &m);
    while(m--) {
        char op[5];
        int u, v;
        scanf("%s%d%d", op, &u, &v);
        if(op[0] == 'C') {
            pair<int, int> ed = edge[u];
            if(dep[ed.first] > dep[ed.second]) u = ed.first;
            else u = ed.second;
            seg.edit(1, 1, n, dfn[u], v);
        } else if(op[0] == 'N') {
            rev(u + 1, v + 1);
        } else if(op[0] == 'S') {
            printf("%d\n", f(u + 1, v + 1, 0));
        } else if(op[1] == 'A') {
            printf("%d\n", f(u + 1, v + 1, 1));
        } else {
            printf("%d\n", f(u + 1, v + 1, 2));
        }
    }
    return 0;
}