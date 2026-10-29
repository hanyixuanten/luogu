#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, k;
int up;
vector<int> fri[300005];
int fa[3000005];
int cnt[300005];
int son[300005];
int dfn[300005];
int rev[300005];
int top[300005];
int dep[300005];
int nowdfn;
struct SEG{
    int num[51][1200005];
    void init(int now, int nl, int nr) {
        if(nl == nr) {
            num[0][now] = 1;
            for(int i = 1; i <= 50; ++i)
                num[i][now] = (1ll * num[i - 1][now] * dep[rev[nl]]) % mod;
            return;
        }
        int nmid = (nl + nr) >> 1;
        init(now * 2, nl, nmid);
        init(now * 2 + 1, nmid + 1, nr);
        for(int i = 1; i <= 50; ++i) num[i][now] = (1ll * num[i][now * 2] + num[i][now * 2 + 1]) % mod;
    }
    int query(int now, int nl, int nr, int l, int r) {
        if(nl > r || nr < l) return 0;
        if(l <= nl && nr <= r) return num[k][now];
        int nmid = (nl + nr) >> 1;
        return (1ll * query(now * 2, nl, nmid, l, r) + query(now * 2 + 1, nmid + 1, nr, l, r)) % mod;
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
    rev[nowdfn] = now;
    top[now] = from;
    if(son[now]) dfs2(son[now], from);
    for(int i : fri[now]) {
        if(i == fa[now] || i == son[now]) continue;
        dfs2(i, i);
    }
}
int query(int a, int b) {
    int ans = 0;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ans = (ans + 1ll * seg.query(1, 1, n, dfn[top[a]], dfn[a])) % mod;
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    ans = (ans + 1ll * seg.query(1, 1, n, dfn[b], dfn[a])) % mod;
    return ans;
}
int main() {
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    seg.init(1, 1, n);
    scanf("%d", &m);
    for(up = 1; up <= m; ++up) {
        int i, j;
        scanf("%d%d%d", &i, &j, &k);
        printf("%d\n", query(i, j));
    }
    return 0;
}