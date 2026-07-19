#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, s;
struct k
{
    int w, v;
} kuang[200005];
struct q
{
    int l, r;
} qu[200005];
int precnt[200005], pre[200005];
/*
大于W的数量*大于W的v的和
*/
int query(int w)
{
    memset(precnt, 0, sizeof precnt);
    memset(pre, 0, sizeof pre);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (kuang[i].w > w)
            pre[i] = pre[i - 1] + kuang[i].v, precnt[i] = precnt[i - 1] + 1;
        else
            pre[i] = pre[i - 1], precnt[i] = precnt[i - 1];
    }
    for (int i = 1; i <= m; ++i)
    {
        int cnt = precnt[qu[i].r] - precnt[qu[i].l - 1], sumv = pre[qu[i].r] - pre[qu[i].l - 1];
        // for (int j = qu[i].l; j <= qu[i].r; ++j)
        // {
        //     if (kuang[j].w > w)
        //         cnt++, sumv += kuang[j].v;
        // }
        ans += cnt * sumv;
    }
    return ans - s;
}
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &s);
    int maxwj = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld", &kuang[i].w, &kuang[i].v);
        maxwj = max(maxwj, kuang[i].w);
    }
    for (int i = 1; i <= m; ++i)
        scanf("%lld%lld", &qu[i].l, &qu[i].r);
    int l = 0, r = LONG_LONG_MAX, mid;
    int ans = LONG_LONG_MAX;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (query(mid) < 0)
            r = mid - 1;
        else
            l = mid + 1;
        ans = min(abs(query(mid)), ans);
    }
    printf("%lld\n", ans);
    /*
    int mina = INT_MAX;
    for (int i = 0; i <= r; ++i)
    {
        mina = min(mina, abs(query(i)));
    }
    printf("%d\n", mina);*/
    return 0;
}