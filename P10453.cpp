// 105
#include <bits/stdc++.h>
#define int long long
using namespace std;
int roww[100005], coll[100005];
int crow[100005], ccol[100005];
int n, m, t;
int row()
{
    int v = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += roww[i];
    if (sum % n)
        return -1;
    v = sum / n;
    for (int i = 1; i <= n; i++)
        crow[i] = crow[i - 1] + roww[i] - v;
    crow[1] = crow[n] + roww[1] - v;
    sort(crow + 1, crow + 1 + n);
    int ans = 0, mi = crow[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
        ans += abs(mi - crow[i]);
    return ans;
}
int col()
{
    int v = 0, sum = 0;
    for (int i = 1; i <= m; ++i)
        sum += coll[i];
    if (sum % m)
        return -1;
    v = sum / m;
    for (int i = 1; i <= m; i++)
        ccol[i] = ccol[i - 1] + coll[i] - v;
    ccol[1] = ccol[m] + coll[1] - v;
    sort(ccol + 1, ccol + 1 + m);
    int ans = 0, mi = ccol[(m + 1) / 2];
    for (int i = 1; i <= m; i++)
        ans += abs(mi - ccol[i]);
    return ans;
}
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &t);
    for (int i = 1; i <= t; ++i)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);
        roww[x]++;
        coll[y]++;
    }
    int rrw = row(), rco = col();
    if (rrw == -1)
        if (rco == -1)
            printf("impossible\n");
        else
            printf("column %lld\n", rco);
    else if (rco == -1)
        printf("row %lld\n", rrw);
    else
        printf("both %lld\n", rco + rrw);

    return 0;
}