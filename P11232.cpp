#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll d, v, a;
    int l, r;  // 超速时对应的测速仪区间下标
    bool over; // 是否超速
} car[100005];

bool cmp(const node &x, const node &y)
{
    return x.r < y.r;
}
ll p[100005];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        ll L, V;
        scanf("%d%d%lld%lld", &n, &m, &L, &V);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld%lld", &car[i].d, &car[i].v, &car[i].a);
            car[i].over = false;
        }
        for (int i = 1; i <= m; ++i)
            scanf("%lld", &p[i]);
        sort(p + 1, p + m + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ll d = car[i].d, v0 = car[i].v, a = car[i].a;
            if (a == 0)
            {
                if (v0 > V)
                {
                    int idx = lower_bound(p + 1, p + m + 1, d) - p;
                    if (idx <= m)
                    {
                        car[i].over = true;
                        car[i].l = idx;
                        car[i].r = m;
                    }
                }
            }
            else if (a > 0)
            {
                int idx;
                if (v0 > V)
                {
                    idx = lower_bound(p + 1, p + m + 1, d) - p;
                }
                else
                {
                    ll x = d + (V * V - v0 * v0) / (2 * a) + 1;
                    idx = lower_bound(p + 1, p + m + 1, x) - p;
                }
                if (idx <= m)
                {
                    car[i].over = true;
                    car[i].l = idx;
                    car[i].r = m;
                }
            }
            else
            { // a < 0
                if (v0 > V)
                {
                    int L = lower_bound(p + 1, p + m + 1, d) - p;
                    ll num = v0 * v0 - V * V;
                    ll den = -2 * a;
                    ll fn = d + (num + den - 1) / den;
                    int R = lower_bound(p + 1, p + m + 1, fn) - p - 1;
                    if (L <= m && L <= R)
                    {
                        car[i].over = true;
                        car[i].l = L;
                        car[i].r = R;
                    }
                }
            }
            if (car[i].over)
                ans++;
        }
        vector<node> over;
        for (int i = 1; i <= n; ++i)
        {
            if (car[i].over)
                over.push_back(car[i]);
        }
        sort(over.begin(), over.end(), cmp);
        int choose = 0;
        int last = -1;
        for (auto &now : over)
        {
            if (now.l > last)
            {
                last = now.r;
                choose++;
            }
        }

        printf("%d %d\n", ans, m - choose);
    }
    return 0;
}