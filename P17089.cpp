#include <bits/stdc++.h>
using namespace std;
int n, s;
struct wx
{
    int w, x;
    inline const bool operator<(const wx a) const
    {
        return w > a.w;
    }
} ball[505];
set<int> f[505]; // 有j的体力时，当前最优方案中球的最终落点
long long ans[505]; // 有j的体力时，当前最优方案的坐标和
/*
f[0][*]=0;
f[*][0]=0;
f[i][j]=max(f[i-1][j-a[i]]+w[i],f[i-1][j]);
*/
int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &ball[i].w);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &ball[i].x);
    sort(ball + 1, ball + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = s; j >= ball[i].x; --j)
        {
            int tmp = ball[i].w;
            for (int k : f[j - ball[i].x])
            {
                if (k == tmp)
                    ++tmp;
            }
            if (ans[j - ball[i].x] + tmp > ans[j])
            {
                ans[j] = ans[j - ball[i].x] + tmp;
                f[j] = f[j - ball[i].x];
                f[j].insert(tmp);
            }
        }
        for (int j = 1; j <= s; ++j)
        {
            if (ans[j - 1] > ans[j])
            {
                ans[j] = ans[j - 1];
                f[j] = f[j - 1];
            }
        }
    }
    printf("%lld\n", ans[s]);
    return 0;
}