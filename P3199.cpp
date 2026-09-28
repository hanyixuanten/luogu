#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, double>> fri[3005];
int q[30000005];
double d[3005];
bool in[3005];
int cnt[3005];
int ql = 1, qr = 0;
bool check(double minus)
{
    ql = 1, qr = 0;
    memset(d, 0, sizeof d);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i)
    {
        q[++qr] = i;
        in[i] = 1;
    }
    while (qr >= ql)
    {
        int now = q[ql++];
        in[now] = 0;
        for (pair<int, double> to : fri[now])
        {
            if (d[now] + to.second - minus < d[to.first])
            {
                d[to.first] = d[now] + to.second - minus, cnt[to.first]++;
                if (!in[to.first])
                    q[++qr] = to.first, in[to.first] = 1;
            }
            if (cnt[to.first] > n)
                return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        double w;
        scanf("%d%d%lf", &u, &v, &w);
        fri[u].push_back({v, w});
    }
    double l = -1e7, r = 1e7;
    while (r - l > 1e-9)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.8lf\n", l);
    return 0;
}