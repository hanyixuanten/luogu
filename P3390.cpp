#include <bits/stdc++.h>
const int mod = 1e9 + 7;
#define int long long
using namespace std;
int n;
struct node
{
    int a[105][105];
    void operator*=(const node &b)
    {
        int res[105][105] = {};
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    res[i][j] += (a[i][k] * b.a[k][j]) % mod;
                    res[i][j] %= mod;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                a[i][j] = res[i][j] % mod;
            }
        }
    }
} a;
long long k;
node pow(node a, int k)
{
    node res;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            res.a[i][j] = (i == j);
    while (k)
    {
        if (k & 1)
            res *= a;
        a *= a;
        k >>= 1;
    }
    while (k)
    {
        if (k & 1)
            res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%lld", &a.a[i][j]);
        }
    }
    node res = pow(a, k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%lld ", res.a[i][j]);
        }
        puts("");
    }
    return 0;
}