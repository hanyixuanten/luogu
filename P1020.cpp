#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 3;
int n, t, a[MAXN], f[MAXN];
int main()
{
    freopen("test.in", "r", stdin);
    while (~scanf("%d", &a[++n]))
        ;
    --n;
    f[0] = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = t + 1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (f[m] >= a[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t)
            t = x;
        f[x] = a[i];
    }
    printf("%d\n", t);
    t = 0, memset(f, 0, sizeof(f)), f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = t + 1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (f[m] < a[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t)
            t = x;
        f[x] = a[i];
    }
    printf("%d\n", t);
    return 0;
}
