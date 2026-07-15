#include <bits/stdc++.h>
#define int long long
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int ans = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ans;
}
signed main()
{
    // freopen("frog.in", "r", stdin);
    // freopen("frog.out", "w", stdout);
    int a, b, x, y, n, m, l;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &m, &n, &l);
    int ans = exgcd(m - n, l, x, y), mod = abs(l / ans);
    if ((b - a) % ans)
    {
        printf("Impossible\n");
        return 0;
    }
    x = (x * ((b - a) / ans) % mod + mod) % mod;
    printf("%lld\n", x);
    return 0;
}