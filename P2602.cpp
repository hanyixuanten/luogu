#include <bits/stdc++.h>
using namespace std;
#define int long long

int dig[20], len;
int dp[20][20][2][2]; // pos, cnt, limm, fl
int dfs(int pos, int cnt, bool limm, bool fl, int too)
{
    if (pos == len)
        return cnt;
    if (dp[pos][cnt][limm][fl] != -1)
        return dp[pos][cnt][limm][fl];
    int up = limm ? dig[pos] : 9;
    int res = 0;
    for (int d = 0; d <= up; ++d)
    {
        bool nl = fl && (d == 0);
        int add = 0;
        if (!(fl && d == 0) && d == too)
            add = 1;
        res += dfs(pos + 1, cnt + add, limm && (d == up), nl, too);
    }
    return dp[pos][cnt][limm][fl] = res;
}
int doo(int n, int too)
{
    if (n <= 0)
        return 0;
    len = 0;
    while (n)
    {
        dig[len++] = n % 10;
        n /= 10;
    }
    reverse(dig, dig + len);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, true, true, too);
}
signed main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= 9; ++i)
    {
        cout << doo(b, i) - doo(a - 1, i) << ' ';
    }
    return 0;
}