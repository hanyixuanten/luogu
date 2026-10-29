#include<bits/stdc++.h>
using namespace std;
int n, m, r, p;
int a[100005];
vector<int> fri[100005];
int dep[100005];
int cnt[100005];
int fa[100005];
int son[100005];
int top[100005];
int dfn[100005];
int nowdfn = 0;
struct seg{
    int num[400005], lt[400005];
    void pu(int now) {
        num[now] = (num[now * 2] + num[now * 2 + 1]) % p;
    }
    void pd(int now, int nl, int nr) {
        int l = lt[now], nmid = (nl + nr) >> 1;
        num[now * 2] = (1ll * num[now * 2] + l * (nmid - nl + 1)) % p;
        num[now * 2 + 1] = (1ll * num[now * 2 + 1] + l * (nr - nmid)) % p;
        lt[now * 2] = (lt[now * 2] + l) % p;
        lt[now * 2 + 1] = (lt[now * 2 + 1] + l) % p;
        lt[now] = 0;
    }
    void add(int now, int nl, int nr, int l, int r, int nn) {
        if(nl > r || nr < l) return;
        if(l <= nl && nr <= r) {
            num[now] = (1ll * (nn) * (nr - nl + 1) + num[now]) % p;
            lt[now] = (lt[now] + nn) % p;
            return;
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        add(now * 2, nl, nmid, l, r, nn);
        add(now * 2 + 1, nmid + 1, nr, l, r, nn);
        pu(now);
    }
    int query(int now, int nl, int nr, int l, int r) {
        if(nl > r || nr < l) return 0;
        if(l <= nl && nr <= r) {
            return num[now] % p;
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        return (query(now * 2, nl, nmid, l, r) + query(now * 2 + 1, nmid + 1, nr, l, r)) % p;
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
        if(cnt[i] > cnt[son[now]]) son[now] = i;
    }
}
void dfs2(int now, int from) {
    dfn[now] = ++nowdfn;
    top[now] = from;
    // bit.add(nowdfn, nowdfn, a[now]);
    seg.add(1, 1, n, nowdfn, nowdfn, a[now]);
    if(son[now])
        dfs2(son[now], top[now]);
    for(int i : fri[now]) {
        if(i == fa[now] || i == son[now]) continue;
        dfs2(i, i);
    }
}
void pathadd(int x, int y, int nn) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        seg.add(1, 1, n, dfn[top[x]], dfn[x], nn);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    seg.add(1, 1, n, dfn[y], dfn[x], nn);
}
int query(int x, int y) {
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = (ans + seg.query(1, 1, n, dfn[top[x]], dfn[x])) % p;
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    return (ans + seg.query(1, 1, n, dfn[y], dfn[x])) % p;
}
void adds(int x, int nn) {
    seg.add(1, 1, n, dfn[x], dfn[x] + cnt[x] - 1, nn);
}
int querys(int x) {
    return seg.query(1, 1, n, dfn[x], dfn[x] + cnt[x] - 1) % p;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &r, &p);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(r, -1);
    dfs2(r, r);
    while(m--) {
        int op, x, y, z;
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d%d", &x, &y, &z);
            pathadd(x, y, z);
        } else if(op ==2) {
            scanf("%d%d", &x, &y);
            printf("%d\n", query(x, y));
        } else if(op == 3) {
            scanf("%d%d", &x, &z);
            adds(x, z);
        } else {
            scanf("%d", &x);
            printf("%d\n", querys(x));
        }
    }
    return 0;
}