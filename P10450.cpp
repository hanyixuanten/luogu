// 102
// https://www.luogu.com.cn/article/42ly2wrn
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l;
int sum[100005];
int q[100005];
int t, h;
double calc(int x, int y)
{
    return (0.0 + sum[y] - sum[x]) / (y - x);
}
signed main()
{
    scanf("%lld%lld", &n, &l);
    for (int i = 1, x; i <= n; ++i)
        scanf("%lld", &x), sum[i] = sum[i - 1] + x;
    double ans = 0;
    for (int i = l; i <= n; ++i) // lp
    {
        while (t - h >= 2 && calc(i - l, q[t - 1]) < calc(i - l, q[t - 2]))
            t--;
        q[t++] = i - l;
        while (t - h >= 2 && calc(i, q[h]) < calc(i, q[h + 1]))
            h++;
        ans = max(ans, calc(i, q[h]));
    }
    printf("%lld\n", (long long)floor(1000 * ans));
    return 0;
}
/*
连续子序列平均值就转化为S-x平面上的斜率：avg(x,y)=(S(y)-s(x-1))/(y-x+1)
*/