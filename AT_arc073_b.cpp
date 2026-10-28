#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n; // 100
int w; // 1e9
pair<int, int> obj[105];
int dp[105][105][305];
int w1;
int main()
{
    // freopen("satchel.in", "r", stdin);
    // freopen("satchel.out", "w", stdout);
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &obj[i].first, &obj[i].second);
        if (i == 1)
            w1 = obj[1].first;
        obj[i].first -= w1;
    }
    int maxS = 3 * n;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int d = obj[i].first;
        int v = obj[i].second;
        for (int k = 0; k <= i; ++k)
        {
            for (int s = 0; s <= maxS; ++s)
            {
                dp[i][k][s] = dp[i - 1][k][s];
                if (k >= 1 && s >= d && dp[i - 1][k - 1][s - d] != -1)
                    dp[i][k][s] = max(dp[i][k][s], dp[i - 1][k - 1][s - d] + v);
            }
        }
    }
    int ans = 0;
    for (int k = 0; k <= n; ++k)
        for (int s = 0; s <= maxS; ++s)
        {
            if (dp[n][k][s] == -1)
                continue;
            if (1LL * k * w1 + s <= w)
                ans = max(ans, dp[n][k][s]);
        }
    printf("%d\n", ans);
    return 0;
}