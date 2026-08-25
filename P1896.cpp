#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, kk;
int dp[15][1100][100];
int check(int j)
{
    if (((j << 1) | (j >> 1)) & j)
        return -1;
    return __builtin_popcount(j);
}
bool check(int a, int b)
{
    return (check(a) == -1 || check(b) == -1) ? 0 : !((a << 1 | a >> 1 | a) & b);
}
signed main()
{
    scanf("%lld%lld", &n, &kk);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            int cou = check(j);
            if (cou != -1)
            {
                for (int jj = 0; jj < (1 << n); jj++)
                {
                    if (check(j, jj))
                    {
                        for (int k = cou; k <= kk; ++k)
                        {
                            dp[i][j][k] += dp[i - 1][jj][k - cou];
                        }
                    }
                }
            }
        }
    }
    int anss = 0;
    for (int j = 0; j < (1 << n); j++)
        anss += dp[n][j][kk];
    printf("%lld\n", anss);
    return 0;
}