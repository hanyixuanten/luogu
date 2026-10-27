#include <bits/stdc++.h>
using namespace std;
struct node {int l, r, res = 0, h;};
const int N = 1e6 + 7;
int n, m, k, h[N], t[N];
vector<node> tr[N * 4];
bool operator<(const node &a, const node &b) { return a.h < b.h; }
node operator+(const node &a, const node &b)
{
    if (!a.res)
        return b;
    if (!b.res)
        return a;
    node ret;
    ret.h = max(a.h, b.h), ret.l = a.l, ret.r = b.r;
    ret.res = a.res + b.res - ((a.r == b.l)?1:0);
    return ret;
}
void pu(int p)
{
    int t1 = 0, t2 = 0;
    while (t1 < (int)tr[p << 1].size() || t2 < (int)tr[p << 1 | 1].size())
    {
        if (t2 == (int)tr[p << 1 | 1].size() || (t1 < (int)tr[p << 1].size() && tr[p << 1][t1] < tr[p << 1 | 1][t2]))
        {
            if (t2)
                tr[p].push_back(tr[p << 1][t1++] + tr[p << 1 | 1][t2 - 1]);
            else
                tr[p].push_back(tr[p << 1][t1++]);
        }
        else
        {
            if (t1)
                tr[p].push_back(tr[p << 1][t1 - 1] + tr[p << 1 | 1][t2++]);
            else
                tr[p].push_back(tr[p << 1 | 1][t2++]);
        }
    }
}
void add(int p, int l, int r, int pos, int h, int t)
{
    if (l == r)
    {
        tr[p].push_back({t, t, 1, h});
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        add(p << 1, l, mid, pos, h, t);
    else
        add(p << 1 | 1, mid + 1, r, pos, h, t);
    if (r == pos)
        pu(p);
}
node qu(int p, int l, int r, int lq, int rq, int h)
{
    if (lq <= l && rq >= r)
    {
        if (tr[p][0].h > h)
            return node{0, 0, 0, 0};
        int pos = upper_bound(tr[p].begin(), tr[p].end(), node{0, 0, 0, h}) - tr[p].begin() - 1;
        return tr[p][pos];
    }
    int mid = (l + r) >> 1;
    if (rq <= mid)
        return qu(p << 1, l, mid, lq, rq, h);
    if (lq > mid)
        return qu(p << 1 | 1, mid + 1, r, lq, rq, h);
    return qu(p << 1, l, mid, lq, rq, h) + qu(p << 1 | 1, mid + 1, r, lq, rq, h);
}
signed main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; i++)
        add(1, 1, n + m, i, h[i], t[i]);
    int lst = 0, cnt = n;
    int l, r, x, y;
    for(int i = 1; i <= m; ++i)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &l, &r, &x), l ^= k * lst, r ^= k * lst, x ^= k * lst;
            lst = qu(1, 1, n + m, l, r, x).res;
            printf("%d\n", lst);
        }
        else
        {
            scanf("%d%d", &x, &y), x ^= k * lst, y ^= k * lst;
            add(1, 1, n + m, ++cnt, x, y);
        }
    }
    return 0;
}