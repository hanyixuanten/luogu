#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l, r, num;
    bool lazy_tag;
} seg[400005];
void init(int now, int l, int r)
{
    seg[now].l = l, seg[now].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    init(now * 2, l, mid);
    init(now * 2 + 1, mid + 1, r);
}
void apply(int now)
{
    seg[now].num = seg[now].r - seg[now].l + 1 - seg[now].num;
    seg[now].lazy_tag = !seg[now].lazy_tag;
}
void pushdown(int now)
{
    if (!seg[now].lazy_tag)
        return;
    apply(now * 2);
    apply(now * 2 + 1);
    seg[now].lazy_tag = false;
}
void modify(int now, int l, int r)
{
    if (l <= seg[now].l && r >= seg[now].r)
    {
        apply(now);
        return;
    }
    pushdown(now);
    int mid = (seg[now].l + seg[now].r) >> 1;
    if (l <= mid)
        modify(now * 2, l, r);
    if (r > mid)
        modify(now * 2 + 1, l, r);
    seg[now].num = seg[now * 2].num + seg[now * 2 + 1].num;
}
int query(int now, int l, int r)
{
    if (l <= seg[now].l && r >= seg[now].r)
        return seg[now].num;
    pushdown(now);
    int mid = (seg[now].l + seg[now].r) >> 1;
    int answer = 0;
    if (l <= mid)
        answer += query(now * 2, l, r);
    if (r > mid)
        answer += query(now * 2 + 1, l, r);
    return answer;
}
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    init(1, 1, n);
    while (m--)
    {
        int c, l, r;
        scanf("%d%d%d", &c, &l, &r);
        if (c == 0)
            modify(1, l, r);
        else
            printf("%d\n", query(1, l, r));
    }
    return 0;
}