#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int p[1000005];
vector<int> fri[1000005];
int bc[1000005];
vector<pair<int, int>> ST;
int find(int now) {
    if(bc[now] == now) return now;
    return bc[now] = find(bc[now]);
}
int dps[1000005][2], dpt[1000005][2];
void dfs(int now, bool s, int from, int st) {
    if(s) dps[now][1] = p[now];
    else dpt[now][1] = p[now];
    if(s && now == st) dps[now][1] = LLONG_MIN;
    else if(!s && now == st) dpt[now][1] = LLONG_MIN;
    for(int i:fri[now]) {
        if(i == from) continue;
        dfs(i, s, now, st);
        if(s) dps[now][1] += dps[i][0], dps[now][0] += max(dps[i][0], dps[i][1]);
        else dpt[now][1] += dpt[i][0], dpt[now][0] += max(dpt[i][0], dpt[i][1]);
    }
}
signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        bc[i] = i;
    }
    for(int i = 1, v; i <= n; ++i) {
        scanf("%lld%lld", &p[i], &v);
        if(find(i) == find(v)) {
            ST.push_back({i, v});
        } else {
            fri[i].push_back(v);
            fri[v].push_back(i);
            bc[find(i)] = find(v);
        }
    }
    int ans = 0;
    for(auto [s, t]:ST){
        dfs(s, 1, -1, s);
        dfs(t, 0, -1, t);
        ans += max(max(dps[s][0], dps[s][1]), max(dpt[t][1], dpt[t][0]));
    }
    printf("%lld\n", ans);
    return 0;
}