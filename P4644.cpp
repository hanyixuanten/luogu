// P4644
#include <bits/stdc++.h>
struct node
{
    int l, r, s;
} a[10010];
int n, m, e;
using namespace std;
bool cmp(node x, node y)
{
    return x.r < y.r;
}
long long f[86400];
int main()
{
    // freopen("cleaning.in", "r", stdin);
    // freopen("cleaning.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &e);
    ++m, ++e;
    memset(f, 0x7f, sizeof(f));
    f[m - 1] = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].s);
        ++a[i].l, ++a[i].r;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        long long minfj = 0x7f7f7f7f7f7f7f7f;
        for (int j = max(m - 1, a[i].l - 1); j <= min(e, a[i].r - 1); ++j)
            if (f[j] < minfj)
                minfj = f[j];
        f[min(a[i].r, e)] = min(f[min(a[i].r, e)], minfj + a[i].s);
    }

    printf("%lld\n", (f[e] == 0x7f7f7f7f7f7f7f7f) ? -1 : f[e]);
    return 0;
}
// 设f[x]为清理[L,x]需要花费的最小代价
// f[min(a[i].r,e)]=min(f[j])+a[i].s (max(L-1,a[i].l-1)<=j<=min(R,c[i].r-1))