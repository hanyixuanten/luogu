// 126
#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[105][105], sum[105][105];
int query(int xx1, int yy1, int xx2, int yy2)
{
    return sum[xx2][yy2] - sum[xx1 - 1][yy2] - sum[xx2][yy1 - 1] + sum[xx1 - 1][yy1 - 1];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]), sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    int ans = -2147482648;
    for (int xx1 = 1; xx1 <= n; ++xx1)
        for (int yy1 = 1; yy1 <= n; ++yy1)
            for (int xx2 = xx1; xx2 <= n; ++xx2)
                for (int yy2 = yy1; yy2 <= n; ++yy2)
                    if (query(xx1, yy1, xx2, yy2) > ans)
                        ans = query(xx1, yy1, xx2, yy2);
    printf("%d", ans);
    return 0;
}