#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll T_BC = 1721424LL;
const ll jend = 577737LL;
const int ds[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool runac(int y) { return y % 4 == 0; }
bool runbc(int y) { return y % 4 == 1; }
bool runac_new(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
ll count_run(ll N)
{
    if (N <= 0)
        return 0;
    return N / 4 - N / 100 + N / 400;
}
ll days_bc(int y)
{
    ll years = 4713 - y;
    ll leaps = 1179 - (y + 3) / 4;
    return years * 365 + leaps;
}
ll days_ac(int y)
{
    ll years = y - 1;
    ll leaps = years / 4;
    return years * 365 + leaps;
}
ll days_new(ll y)
{
    if (y <= 1583)
        return 0;
    ll years = y - 1583;
    ll leaps = count_run(y - 1) - count_run(1582);
    return years * 365 + leaps;
}
pair<int, int> gett(ll q, bool run)
{
    int days[13];
    for (int i = 1; i <= 12; ++i)
        days[i] = ds[i];
    if (run)
        days[2] = 29;
    int month = 1;
    while (q >= days[month])
    {
        q -= days[month];
        ++month;
    }
    return {month, (int)q + 1};
}
void solve(ll r)
{
    if (r < T_BC)
    {
        int el = 1, er = 4713;
        while (el < er)
        {
            int mid = (el + er) / 2;
            if (days_bc(mid) <= r)
                er = mid;
            else
                el = mid + 1;
        }
        int y = el;
        ll q = r - days_bc(y);
        bool run = runbc(y);
        auto [m, d] = gett(q, run);
        printf("%d %d %d BC\n", d, m, y);
    }
    else
    {
        r -= T_BC;
        if (r < jend)
        {

            int el = 1, er = 1582;
            while (el < er)
            {
                int mid = (el + er + 1) / 2;
                if (days_ac(mid) <= r)
                    el = mid;
                else
                    er = mid - 1;
            }
            int y = el;
            ll q = r - days_ac(y);
            bool run = runac(y);
            auto [m, d] = gett(q, run);
            printf("%d %d %d\n", d, m, y);
        }
        else
        {
            r -= jend;
            if (r < 78)
            {
                int y = 1582, m, d;
                if (r < 17)
                {
                    m = 10;
                    d = 15 + r;
                }
                else
                {
                    r -= 17;
                    if (r < 30)
                    {
                        m = 11;
                        d = 1 + r;
                    }
                    else
                    {
                        r -= 30;
                        m = 12;
                        d = 1 + r;
                    }
                }
                printf("%d %d %d\n", d, m, y);
            }
            else
            {
                r -= 78;
                ll el = 1583, er = 1000000000LL + 1000000;
                while (el < er)
                {
                    ll mid = (el + er + 1) / 2;
                    if (days_new(mid) <= r)
                        el = mid;
                    else
                        er = mid - 1;
                }
                ll y = el;
                ll q = r - days_new(y);
                bool run = runac_new((int)y);
                auto [m, d] = gett(q, run);
                printf("%d %d %lld\n", d, m, y);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll q;
        scanf("%lld", &q);
        solve(q);
    }
    return 0;
}