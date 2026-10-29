#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[300005];
int fa[300005];
int dfn[300005];
int son[300005];
int dep[300005];
int top[300005];
int cnt[300005];
vector<int> fri[300005];
int dfnnow;
struct SEG{
    int num[1200005], lt[1200005];
    void pu(int now) {
        num[now] = num[now * 2] + num[now * 2 + 1];
    }
    void pd(int now, int nl, int nr) {
        int nmid = (nl + nr) >> 1, l = lt[now];
        num[now * 2] += l * (nmid - nl + 1);
        num[now * 2 + 1] += l * (nr - nmid);
        lt[now * 2] += l;
        lt[now * 2 + 1] += l;
        lt[now] = 0;
    }
    void add(int now, int nl, int nr, int l, int r, int nn) {
        if(nr < l || nl > r) return;
        if(l <= nl && nr <= r) {
            num[now] += (nr - nl + 1) * nn;
            lt[now] += nn;
            return;
        }
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        add(now * 2, nl, nmid, l, r, nn);
        add(now * 2 + 1, nmid + 1, nr, l, r, nn);
        pu(now);
    }
    int query(int now, int nl, int nr, int l, int r) {
        if(nr < l || nl > r) return 0;
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
    top[now] = from;
    dfn[now] = ++dfnnow;
    if(son[now]) dfs2(son[now], from);
    for(int i : fri[now]) {
        if(i == fa[now] || i == son[now]) continue;
        dfs2(i, i);
    }
}
void edit(int a, int b, int nn = 1) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        seg.add(1, 1, n, dfn[top[a]], dfn[a], nn);
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    seg.add(1, 1, n, dfn[b], dfn[a], nn);
}
signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%lld%lld", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, 1);
    for(int i = 1; i < n; ++i) {
        edit(a[i], a[i + 1]);
        edit(a[i + 1], a[i + 1], -1);
    }
    for(int i = 1; i <= n; ++i) {
        printf("%lld\n", seg.query(1, 1, n, dfn[i], dfn[i]));
    }
    return 0;
}