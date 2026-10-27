#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> fri[200005];
int siz[200005];
int f[200005];
int ans[200005];
void dfs(int now, int from) {
    siz[now] = 1;
    f[now] = 0;
    for(int i:fri[now]) {
        if(i == from) continue;
        dfs(i, now);
        f[now] += f[i];
        siz[now] += siz[i];
    }
    f[now] += siz[now];
}
void pass(int now, int from) {
    for(int i:fri[now]) {
        if(i == from) continue;
        ans[i] = ans[now] + n - siz[i] * 2;
        pass(i, now);
    }
}
signed main() {
    scanf("%lld", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%lld%lld", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs(1, -1);
    ans[1] = f[1];
    pass(1, -1);
    int res = ans[1];
    for(int i = 1; i <= n; ++i) res = max(res, ans[i]);
    printf("%lld\n", res);
    return 0;
}
/*
dp[i] 表示 i 子树中将 i 先染色的最大贡献
g u=g father u+n−siz u×2
*/