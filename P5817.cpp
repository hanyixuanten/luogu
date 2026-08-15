#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[300005], c[300005];
signed main()
{
    int n, v = 0, sum = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]), sum += a[i];
    v = sum / n;
    for (int i = 1; i <= n; i++)
        c[i] = c[i - 1] + a[i] - v;
    sort(c + 1, c + 1 + n);
    int ans = 0, mi = c[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
        ans += abs(mi - c[i]);
    printf("%lld\n", ans);
    return 0;
}