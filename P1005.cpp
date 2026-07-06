#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 85;
int n, m;
int a[MAXN][MAXN];
__int128 pow2[MAXN];
__int128 dp[MAXN][MAXN];
void print___int128(__int128 x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    char buf[40];
    int pos = 0;
    while (x > 0)
    {
        buf[pos++] = '0' + (x % 10);
        x /= 10;
    }
    for (int i = pos - 1; i >= 0; i--)
    {
        putchar(buf[i]);
    }
}
__int128 solve_row(int row)
{
    memset(dp, 0, sizeof(dp));
    for (int len = 1; len <= m; len++)
    {
        for (int l = 0; l + len - 1 < m; l++)
        {
            int r = l + len - 1;
            int turn = m - len + 1;
            if (len == 1)
            {
                dp[l][r] = (__int128)a[row][l] * pow2[turn];
            }
            else
            {
                __int128 take_left = (__int128)a[row][l] * pow2[turn] + dp[l + 1][r];
                __int128 take_right = (__int128)a[row][r] * pow2[turn] + dp[l][r - 1];
                dp[l][r] = max(take_left, take_right);
            }
        }
    }
    return dp[0][m - 1];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    pow2[0] = 1;
    for (int i = 1; i <= m; i++)
        pow2[i] = pow2[i - 1] << 1;
    __int128 ans = 0;
    for (int i = 0; i < n; i++)
        ans += solve_row(i);
    print___int128(ans);
    putchar('\n');
    return 0;
}