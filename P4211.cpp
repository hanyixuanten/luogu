#include<bits/stdc++.h>
const int mod = 201314;
using namespace std;
int n, m;
vector<int> chi[50005];
int fa[50005];
int cnt[50005];
int son[50005];
int top[50005];
int dep[50005];
int dfn[50005];
int nowdfn;
pair<int, int> query[100005];
struct SEG{
    int num[400005], lt[400005];
    void pu(int now) {num[now] = (1ll * num[now * 2] + num[now * 2 + 1]) % mod;}
    void pd(int now, int nl, int nr) {
        int nmid = (nl + nr) >> 1;
        num[now * 2] = (num[now * 2] + 1ll * (nmid - nl + 1) * lt[now]) % mod;
        num[now * 2 + 1] = (num[now * 2 + 1] + 1ll * (nr - nmid) * lt[now]) % mod;
        lt[now * 2] = (lt[now * 2] + lt[now]) % mod;
        lt[now * 2 + 1] = (lt[now * 2 + 1] + lt[now]) % mod;
        lt[now] = 0;
    }
    void add(int now, int nl, int nr, int l, int r, int nn) {
        if(nl > r || nr < l) return;
        if(l <= nl && nr <= r) {
            num[now] = (num[now] + 1ll * (nr - nl + 1) * nn) % mod;
            lt[now] = (lt[now] + 1ll * nn) % mod;
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
            return num[now];
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        return (1ll * query(now * 2, nl, nmid, l, r) + query(now * 2 + 1, nmid + 1, nr, l, r)) % mod;
    }
}seg;
void dfs1(int now) {
    cnt[now] = 1;
    for(int i : chi[now]) {
        dep[i] = dep[now] + 1;
        dfs1(i);
        cnt[now] += cnt[i];
        if(cnt[son[now]] < cnt[i]) son[now] = i;
    }
}
void dfs2(int now, int from) {
    top[now] = from;
    dfn[now] = ++nowdfn;
    if(son[now]) dfs2(son[now], from);
    for(int i : chi[now]) {
        if(i == son[now]) continue;
        dfs2(i, i);
    }
}
void addpath(int a, int b = 1) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        seg.add(1, 1, n, dfn[top[a]], dfn[a], 1);
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    seg.add(1, 1, n, dfn[b], dfn[a], 1);
}
int querypath(int a, int b = 1) {
    int ans = 0;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ans = (ans + 1ll * seg.query(1, 1, n, dfn[top[a]], dfn[a])) % mod;
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    return (ans + 1ll * seg.query(1, 1, n, dfn[b], dfn[a])) % mod;
}
int sx[100005];
int ans[100005];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &fa[i]);
        fa[i]++;
        chi[fa[i]].push_back(i);
    }
    dfs1(1);
    dfs2(1, 1);
    for(int i = 1, l, r, z; i <= m; ++i) {
        scanf("%d%d%d", &l, &r, &z);
        l++, r++, z++;
        sx[i] = i;
        sx[i + m] = i + m;
        query[2 * i - 1] = {l - 1, z};
        query[2 * i] = {r, z};
    }
    sort(sx + 1, sx + 2 * m + 1, [](int x, int y){return query[x] < query[y];});
    int cur = 0;
    for(int i = 1; i <= 2 * m; ++i) {
        int u = query[sx[i]].first;
        int w = query[sx[i]].second;
        while(cur < u) {
            ++cur;
            addpath(cur);
        }
        ans[sx[i]] = querypath(w);
    }
    for(int i = 1; i <= m; ++i) {
        printf("%d\n", (ans[2 * i] - ans[2 * i - 1] + mod) % mod);
    }
    return 0;
}
/*
从根到 [l, r] 中每个点的路径上的点均 + 1，最否求 z 到根的路径权值和
*/