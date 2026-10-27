#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int p[100005];
vector<int> fri[100005];
long double k;
int bc[100005];
int find(int now) {
    if(bc[now] == now) return now;
    return bc[now] = find(bc[now]);
}
int dps[100005][2], dpt[100005][2];
void dfs(int now, bool s, int from) {
    if(s) dps[now][1] = p[now];
    else dpt[now][1] = p[now];
    if(s && now == T) dps[now][1] = LLONG_MIN;
    else if(!s && now == S) dpt[now][1] = LLONG_MIN;
    for(int i:fri[now]) {
        if(i == from) continue;
        dfs(i, s, now);
        if(s) dps[now][1] += dps[i][0], dps[now][0] += max(dps[i][0], dps[i][1]);
        else dpt[now][1] += dpt[i][0], dpt[now][0] += max(dpt[i][0], dpt[i][1]);
    }
}
signed main() {
    int S, T;
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &p[i]);
        bc[i] = i;
    }
    for(int i = 0, u, v; i < n; ++i) {
        scanf("%lld%lld", &u, &v);
        if(find(u) == find(v)) {
            S = u, T = v;
        } else {
            fri[u].push_back(v);
            fri[v].push_back(u);
            bc[find(u)] = find(v);
        }
    }
    scanf("%llf", &k);
    dfs(S, 1, -1);
    dfs(T, 0, -1);
    int ans = max(max(dps[S][0], dps[S][1]), max(dpt[T][1], dpt[T][0]));
    printf("%.1llf\n", ans * k);
    return 0;
}