#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        int a, b, k, m;
        scanf("%lld%lld%lld%lld", &a, &b, &k, &m);
        int h = (k + sqrt(k * k - 4 * (m - 1 - k))) / 2, v = (k - sqrt(k * k - 4 * (m - 1 - k))) / 2;
        if (h + v != k || h * v != m - 1 - k || max(h, v) >= max(a, b) || min(h, v) >= min(a, b))
            puts("-1");
        else
        {
            if (max(h, v) < b)
                printf("%d %d\n", min(h, v), max(h, v));
            else
                printf("%d %d\n", max(h, v), min(h, v));
        }
    }
    return 0;
}
// (h+1)(v+1)=m
// h+v=k
// hv + k + 1 = m
// x2-kx+hv