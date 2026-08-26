#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int l, r, num;
    int lt;
} seg[400005];
int a[100005];
void init(int now, int l, int r)
{
    seg[now].l = l, seg[now].r = r;
    if (l == r)
    {
        seg[now].num = a[l];
        return;
    }
    int mid = l + r >> 1;
    init(now * 2, l, mid);
    init(now * 2 + 1, mid + 1, r);
    seg[now].num = seg[now * 2].num + seg[now * 2 + 1].num;
}
void pd(int now)
{
    int lt = seg[now].lt;
    seg[now * 2].num += lt * (seg[now * 2].r - seg[now * 2].l + 1), seg[now * 2].lt += lt;
    seg[now * 2 + 1].num += lt * (seg[now * 2 + 1].r - seg[now * 2 + 1].l + 1), seg[now * 2 + 1].lt += lt;
    seg[now].lt = 0;
}
void add(int now, int l, int r, int num)
{
    if (seg[now].r <= r && seg[now].l >= l)
    {
        seg[now].num += num * (seg[now].r - seg[now].l + 1), seg[now].lt += num;
        return;
    }
    if (seg[now].r < l || seg[now].l > r)
    {
        return;
    }
    pd(now);
    add(now * 2, l, r, num);
    add(now * 2 + 1, l, r, num);
    seg[now].num = seg[now * 2].num + seg[now * 2 + 1].num;
}
int query(int now, int l, int r)
{
    if (seg[now].l >= l && seg[now].r <= r)
    {
        return seg[now].num;
    }
    if (seg[now].r < l || seg[now].l > r)
    {
        return 0;
    }
    pd(now);
    return query(now * 2, l, r) + query(now * 2 + 1, l, r);
}
int n, q;
signed main()
{
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    init(1, 1, n);
    while (q--)
    {
        int op;
        scanf("%lld", &op);
        if (op == 1)
        {
            int l, r, k;
            scanf("%lld%lld%lld", &l, &r, &k);
            add(1, l, r, k);
        }
        else
        {
            int l, r;
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}