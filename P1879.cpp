#include <bits/stdc++.h>
#define int long long
const int mod = 100000000;
using namespace std;
int m, n;
int aa[15];
int dp[15][10000];
bool check(int i, int line)
{
    if ((i << 1 | i >> 1) & i) // 行内无相邻
        return 0;
    return (aa[line] & i) == i; // 满足种植条件
}
bool check(int a, int b, int line)
{
    if (!check(a, line) || !check(b, line - 1))
        return 0;
    else
        return !(a & b);
}
signed main()
{
    scanf("%lld%lld", &m, &n);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1, a; j <= n; ++j)
        {
            scanf("%lld", &a);
            aa[i] <<= 1, aa[i] += a;
        }
    }
    for (int j = 0; j < (1 << n); ++j)
        if (check(j, 0))
            dp[0][j] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < (1 << n); ++j)
        {
            if (check(j, i))
            {
                for (int jj = 0; jj < (1 << n); ++jj)
                {
                    if (check(j, jj, i))
                    {
                        dp[i][j] = (dp[i - 1][jj] + dp[i][j]) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < (1 << n); ++j)
        ans = (dp[m][j] + ans) % mod;
    printf("%lld\n", ans);
    return 0;
}