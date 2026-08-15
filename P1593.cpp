// 97
#include <cstdio>
#include <map>
#include <cmath>
#define int long long
using namespace std;
const int mod = 9901;
int pow(int a, int b, int p)
{
    a %= p;
    int res = 1;
    while (b > 0)
    {
        if (b % 2)
            res *= a, res %= p;
        a = a * a % p, b >>= 1;
    }
    return res;
}
signed main()
{
    int a, b;
    scanf("%lld%lld", &a, &b);
    map<int, int> yuec;
    for (int i = 2; a > 1; i++)
        while (a % i == 0)
            yuec[i]++, a /= i;
    int ans = 1;
    for (pair<int, int> i : yuec)
    {
        if ((i.first - 1) % mod == 0)
            ans *= (i.second * b + 1) % mod;
        else
            ans *= (pow(i.first, i.second * b + 1, mod) - 1) * pow(i.first - 1, mod - 2, mod)%mod;
        ans %= mod;
    }
    if(!a) ans=0;
    printf("%lld\n", (ans+mod)%mod);
    return 0;
}