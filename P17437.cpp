#include <bits/stdc++.h>
#define int long long
using namespace std;
int n; // 5e5
vector<int> fri[500005];
int dep[500005];
int fa[500005];
long long sum[500005];
long long dmin[500005], dmax[500005]; // down max / min
long long umin[500005], umax[500005]; // up 反向的 max和min
int ord[500005], stk[500005];
const long long INF = LLONG_MAX;
const long long _INF = LLONG_MIN;
long long median(long long x, long long y, long long z) {
    long long a[3] = {x, y, z};
    sort(a, a + 3);
    return a[1];
}
int noword;
void dfs(int u) {
    dep[u] = dep[fa[u]] + 1;
    ord[++noword] = u;
    for (int v : fri[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs(v);
    }
}
void pre() {
    noword = 0;
    dfs(1);
    int cnt = noword;
    for (int i = cnt; i >= 1; --i) {
        int now = ord[i];
        dmin[now] = INF;
        dmax[now] = _INF;
        for (int v : fri[now]) {
            if (v == fa[now]) continue;
            sum[now] += sum[v];
            if (sum[v] < dmin[now]) dmin[now] = sum[v];
            if (sum[v] > dmax[now]) dmax[now] = sum[v];
            if (dmin[v] < dmin[now]) dmin[now] = dmin[v];
            if (dmax[v] > dmax[now]) dmax[now] = dmax[v];
        }
    }
    umin[1] = INF;
    umax[1] = _INF;
    for (int i = 1; i <= cnt; ++i) {
        int u = ord[i];
        long long min1 = INF, min2 = INF;
        long long max1 = _INF, max2 = _INF;
        int minid = 0, maxid = 0;
        for (int v : fri[u]) {
            if (v == fa[u]) continue;
            long long mn = sum[v];
            if (dmin[v] < mn) mn = dmin[v];
            long long mx = sum[v];
            if (dmax[v] > mx) mx = dmax[v];
            if (mn < min1) {
                min2 = min1;
                min1 = mn;
                minid = v;
            } else if (mn < min2) {
                min2 = mn;
            }
            if (mx > max1) {
                max2 = max1;
                max1 = mx;
                maxid = v;
            } else if (mx > max2) {
                max2 = mx;
            }
        }
        long long pmin = INF, pmax = _INF;
        if (u != 1) {
            pmin = sum[1] - sum[u];
            if (umin[u] < pmin) pmin = umin[u];
            pmax = sum[1] - sum[u];
            if (umax[u] > pmax) pmax = umax[u];
        }
        for (int v : fri[u]) {
            if (v == fa[u]) continue;
            long long amin = (v == minid ? min2 : min1);
            long long amax = (v == maxid ? max2 : max1);
            umin[v] = pmin < amin ? pmin : amin;
            umax[v] = pmax > amax ? pmax : amax;
        }
    }
}
signed main() {
    // freopen("young.in", "r", stdin);
    // freopen("young.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &sum[i]);
    for (int i = 1, u, v; i < n; ++i)
        scanf("%lld%lld", &u, &v), fri[u].push_back(v), fri[v].push_back(u);
    pre();
    long long ans = _INF;
    for (int v = 2; v <= n; ++v) {
        long long B = sum[1] - sum[v];
        if (dmin[v] != INF)
            ans = max(ans, median(dmin[v], sum[v] - dmin[v], B));
        if (dmax[v] != _INF)
            ans = max(ans, median(dmax[v], sum[v] - dmax[v], B));
        if (umin[v] != INF)
            ans = max(ans, median(umin[v], B - umin[v], sum[v]));
        if (umax[v] != _INF)
            ans = max(ans, median(umax[v], B - umax[v], sum[v]));
    }
    printf("%lld\n", ans);
    return 0;
}
/*
让三块里排在中间的那块尽可能大
先枚举第一条断边
令1为根，用id代表节点id头顶的边
枚举第一个切割，分为两部分 一部分是id的子树 另一部分为sum[1]-sum[id]
第二刀切在id内部或id外部

以 1 为根。求出
S_u 以 u 为根的子树权值和
dmin[u] u 内切，最小连通块权值
dmax[u] u 内切，最大连通块权值

可以直接求（max/min(sum[孩子], dmax/min孩子)）
*/