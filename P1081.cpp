#include <cstdio>
#include <cmath>
#include <set>
#include <map>
using namespace std;
const int maxn = 1e5 + 10;
const int max2 = 20;
const int inf = 2e9 + 5;
struct nextp
{
    int a, b;
} np[maxn];
int n, h[maxn], x0, m;
int f[max2][maxn][2];
long long da[max2][maxn][2], db[max2][maxn][2];
/*
np(i).a/.b 从i出发的下一个点的编号
f(i, j, k) k(0/1) 先走 从 j 出发 经过 2^i 天
da A行驶距离
db B行驶距离
*/
void init_nextp()
{
    set<pair<int, int>> nu;
    nu.insert({inf, n});
    nu.insert({inf - 1, n});
    nu.insert({-inf, n});
    nu.insert({-inf + 1, n});
    for (int j = n - 1; j >= 0; --j)
    {
        auto t = nu.lower_bound({h[j], j});
        t++;
        pair<int, int> ans[5];
        for (int i = 4; i > 0; --i)
        {
            ans[i] = *t;
            t--;
        }
        int m1 = inf, m2 = inf, mp1 = 0, mp2 = 0;
        for (int i = 1; i <= 4; ++i)
        {
            int d = abs(ans[i].first - h[j]);
            if (d < m1)
            {
                m2 = m1;
                mp2 = mp1;
                m1 = d;
                mp1 = ans[i].second;
            }
            else if (d < m2)
            {
                m2 = d;
                mp2 = ans[i].second;
            }
        }
        np[j].a = mp2;
        np[j].b = mp1;
        nu.insert({h[j], j});
    }
    return;
}
void init_f()
{
    for (int j = 0; j < n; ++j)
    {
        f[0][j][0] = np[j].a, f[0][j][1] = np[j].b;
    }
    f[0][n][0] = f[0][n][1] = n;
    for (int i = 1; i < max2; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k < 2; ++k)
            {
                int mid = f[i - 1][j][k];
                if (mid >= n)
                    f[i][j][k] = n;
                else
                    f[i][j][k] = f[i - 1][mid][(i == 1) ? (k ^ 1) : k];
            }
    return;
}
void init_d()
{
    for (int j = 0; j < n; ++j)
    {
        da[0][j][0] = (np[j].a < n) ? abs(h[j] - h[np[j].a]) : 0;
        db[0][j][0] = 0;
        da[0][j][1] = 0;
        db[0][j][1] = (np[j].b < n) ? abs(h[j] - h[np[j].b]) : 0;
    }
    da[0][n][0] = da[0][n][1] = db[0][n][0] = db[0][n][1] = 0;
    for (int i = 1; i < max2; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k < 2; ++k)
            {
                int mid = f[i - 1][j][k];
                if (mid >= n)
                {
                    da[i][j][k] = 0;
                    db[i][j][k] = 0;
                }
                else
                {
                    int nk = (i == 1) ? (k ^ 1) : k;
                    da[i][j][k] = da[i - 1][j][k] + da[i - 1][mid][nk];
                    db[i][j][k] = db[i - 1][j][k] + db[i - 1][mid][nk];
                }
            }
    return;
}
void query(int s, int x, long long &la, long long &lb)
{
    la = 0;
    lb = 0;
    int cur = s;
    for (int k = max2 - 1; k >= 1; --k)
    {
        if (f[k][cur][0] < n && la + lb + da[k][cur][0] + db[k][cur][0] <= x)
        {
            la += da[k][cur][0];
            lb += db[k][cur][0];
            cur = f[k][cur][0];
        }
    }
    if (f[0][cur][0] < n && la + lb + da[0][cur][0] + db[0][cur][0] <= x)
    {
        la += da[0][cur][0];
        lb += db[0][cur][0];
    }
}
int main()
{
    // freopen("drive.in", "r", stdin);
    // freopen("drive.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &h[i]);
    }
    init_nextp();
    init_f();
    init_d();
    scanf("%d", &x0);
    long long best_a = 0, best_b = 1;
    int mp = -1;
    bool all_zero = true;
    for (int j = 0; j < n; ++j)
    {
        long long la, lb;
        query(j, x0, la, lb);
        if (lb > 0)
        {
            all_zero = false;
            if (mp < 0 || la * best_b < best_a * lb || (la * best_b == best_a * lb && h[j] > h[mp]))
            {
                best_a = la;
                best_b = lb;
                mp = j;
            }
        }
    }
    if (all_zero)
    {
        mp = 0;
        for (int j = 1; j < n; ++j)
        {
            if (h[j] > h[mp])
                mp = j;
        }
    }
    printf("%d\n", mp + 1);
    scanf("%d", &m);
    while (m--)
    {
        int s, x;
        scanf("%d %d", &s, &x);
        long long la, lb;
        query(s - 1, x, la, lb);
        printf("%lld %lld\n", la, lb);
    }
    return 0;
}