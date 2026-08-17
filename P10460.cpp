// 120
#include <bits/stdc++.h>
using namespace std;
int t;
struct node
{
    long long l, r, d;
} a[200005];
int n;
int pre(long long x)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x < a[i].l)
            continue;
        long long end = min(x, a[i].r);
        if (end < a[i].l)
            continue;
        long long cnt = (end - a[i].l) / a[i].d + 1;
        res ^= (cnt & 1);
    }
    return res;
}
long long at(long long p)
{
    long long cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (p < a[i].l || p > a[i].r)
            continue;
        if ((p - a[i].l) % a[i].d == 0)
            ++cnt;
    }
    return cnt;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        long long maxE = 0;

        for (int i = 0; i < n; ++i)
        {
            scanf("%lld%lld%lld", &a[i].l, &a[i].r, &a[i].d);
            maxE = max(maxE, a[i].r);
        }
        if (pre(maxE) == 0)
        {
            puts("There's no weakness.");
            continue;
        }
        long long l = 0, r = maxE;
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (pre(mid) == 1)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%lld %lld\n", l, at(l));
    }
    return 0;
}