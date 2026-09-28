#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
struct node
{
    int a, b, c;
} a[20005];
long double getmax(long double now)
{
    long double ans = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, a[i].a * now * now + a[i].b * now + a[i].c);
    }
    return ans;
}
signed main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
        }
        long double l = 0, r = 1000;
        for (int i = 1; i <= 1000 && l <= r; i++)
        {
            long double lmid = l + (r - l) / 3, rmid = l + 2 * (r - l) / 3;
            long double lans = getmax(lmid), rans = getmax(rmid);
            if (lans > rans)
            {
                l = lmid;
                
            }
            else if (lans < rans)
            {
                r = rmid;
            }
            else
            {
                l = lmid, r = rmid;
            }
        }
        printf("%.4Lf\n", (long double)(getmax(r)));
    }
    return 0;
}