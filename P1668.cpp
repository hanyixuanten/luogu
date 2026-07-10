#include <bits/stdc++.h>
using namespace std;
struct no
{
    int l, r, s;
    inline const bool operator<(const no b) const
    {
        return r < b.r;
    }
} cow[(int)2.5e4 + 1], seg[(int)4e6 + 5];
void init(int now, int l, int r)
{
    seg[now].l = l;
    seg[now].r = r;
    seg[now].s = 0x7f7f7f7f;
    if (l != r)
    {
        init(now * 2, l, (l + r) / 2);
        init(now * 2 + 1, (l + r) / 2 + 1, r);
    }
    return;
}
int query(int now, int l, int r)
{
    if (seg[now].l > r || seg[now].r < l)
        return 0x7f7f7f7f;
    if (seg[now].l >= l && seg[now].r <= r)
        return seg[now].s;
    int mid = (seg[now].l + seg[now].r) / 2;
    if (r <= mid)
        return query(2 * now, l, r);
    else if (l >= mid + 1)
        return query(2 * now + 1, l, r);
    else
        return min(query(2 * now, l, r), query(2 * now + 1, l, r));
}
void edit(int now, int num, int location)
{
    if (seg[now].l == seg[now].r)
    {
        seg[now].s = num;
        return;
    }
    seg[now].s = min(num, seg[now].s);
    int mid = (seg[now].l + seg[now].r) / 2;
    if (location <= mid)
        edit(2 * now, num, location);
    else
        edit(2 * now + 1, num, location);
    return;
}
// int f[(int)2.5e4 + 1]; // 到i最小代价
int n, t;
int main()
{
    // freopen("cleaning.in", "r", stdin);
    // freopen("cleaning.out", "w", stdout);
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &cow[i].l, &cow[i].r);
    }
    sort(cow + 1, cow + n + 1);
    init(1, 0, t);
    edit(1, 0, 0);
    // query(1, 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        // printf("%d\n", i);
        int q = query(1, cow[i].l - 1, cow[i].r - 1);
        if (q + 1 < query(1, cow[i].r, cow[i].r))
            edit(1, q + 1, cow[i].r);
    }
    // for (int i = 0; i <= t; ++i)
    //     printf("%d ", f[i]);
    int ans = query(1, t, t);
    printf("%d\n", (ans > n) ? -1 : ans);
    return 0;
}