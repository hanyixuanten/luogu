#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, m; // 1e5
long long jc[200005];
long long qpow(long long a, long long b)
{
    if (b == 0)
        return 1ll;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = a * res % mod;
        a = a * a % mod, b /= 2;
    }
    return res;
}
long long ni(long long a)
{
    return qpow(a, mod - 2);
}
long long C(long long a, long long b)
{
    return ((jc[a] * ni(jc[a - b])) % mod * ni(jc[b])) % mod;
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    long long now = 1;
    jc[0] = 1;
    for (long long i = 1; i <= m + n; ++i)
        now = now * i % mod, jc[i] = now;
    long long ans = (C(n + m, m) - C(n + m, m - 1));
    while (ans < 0)
        ans += mod;
    printf("%lld\n", ans % mod);
    return 0;
}