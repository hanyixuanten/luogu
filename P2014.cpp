#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 305;
int n, m, s[MAXN];
vector<int> g[MAXN];
int dp[MAXN][MAXN];
int sz[MAXN];
void dfs(int u)
{
    sz[u] = 1;
    for (int j = 0; j <= m + 1; ++j)
        dp[u][j] = INT_MIN;
    dp[u][1] = s[u];
    for (int v : g[u])
    {
        dfs(v);
        for (int i = sz[u]; i >= 1; --i)
        {
            if (dp[u][i] < 0)
                continue;
            for (int k = 1; k <= sz[v] && i + k <= m + 1; ++k)
            {
                if (dp[v][k] < 0)
                    continue;
                dp[u][i + k] = max(dp[u][i + k], dp[u][i] + dp[v][k]);
            }
        }
        sz[u] += sz[v];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int fa;
        cin >> fa >> s[i];
        g[fa].push_back(i);
    }
    s[0] = 0;
    dfs(0);
    cout << dp[0][m + 1] << '\n';
    return 0;
}