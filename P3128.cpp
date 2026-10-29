#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> fri[100005];
int cnt[100005];
int fa[100005];
int son[100005];
int dfn[100005];
int top[100005];
int dep[100005];
int nowdfn;
struct SEG{
    int num[400005], lt[400005];
    void pu(int now) {
        num[now] = num[now * 2] + num[now * 2 + 1];
    }
    void pd(int now, int nl, int nr) {
        int nmid = (nl + nr) >> 1;
        int l = lt[now];
        num[now * 2] += l * (nmid - nl + 1);
        num[now * 2 + 1] += l * (nr - nmid);
        lt[now * 2] += l;
        lt[now * 2 + 1] += l;
        lt[now] = 0;
    }
    void add(int now, int nl, int nr, int l, int r, int nn) {
        if(nl > r || nr < l) return;
        if(l <= nl && nr <= r) {
            num[now] += nn;
            lt[now] += nn;
            return;
        }
        int nmid = (nl + nr) >> 1;
        add(now * 2, nl, nmid, l, r, nn);
        add(now * 2 + 1, nmid + 1, nr, l, r, nn);
        pu(now);
    }
    int query(int now, int nl, int nr, int l, int r) {
        if(nl > r || nr < l) return 0;
        if(l <= nl && nr <= r) {
            return num[now];
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        return query(now * 2, nl, nmid, l, r) + query(now * 2 + 1, nmid + 1, nr, l, r);
    }
}seg;
void dfs1(int now, int from) {
    cnt[now] = 1;
    for(int i : fri[now]) {
        if(i == from) continue;
        fa[i] = now;
        dep[i] = dep[now] + 1;
        dfs1(i, now);
        cnt[now] += cnt[i];
        if(cnt[son[now]] < cnt[i]) son[now] = i;
    }
}
void dfs2(int now, int from) {
    dfn[now] = ++nowdfn;
    top[now] = from;
    if(son[now]) dfs2(son[now], from);
    for(int i : fri[now]) {
        if(i == fa[now] || i == son[now]) continue;
        dfs2(i, i);
    }
}
void add(int a, int b) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        seg.add(1, 1, n, dfn[top[a]], dfn[a], 1);
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    seg.add(1, 1, n, dfn[b], dfn[a], 1);
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, 1);
    while(k--) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, seg.query(1, 1, n, i, i));
    }
    printf("%d\n", ans);
    return 0;
}