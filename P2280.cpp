// 101
#include <cstdio>
#include <algorithm>
using namespace std;
int n, r;
int maxx = 0, maxy = 0;
int sum[5005][5005];
int query(int i, int j)
{
    int x2 = min(maxx, i + r - 1);
    int y2 = min(maxy, j + r - 1);
    return sum[x2][y2] - sum[i - 1][y2] - sum[x2][j - 1] + sum[i - 1][j - 1];
}
int main()
{
    scanf("%d%d", &n, &r);
    for (int x, y, w, i = 1; i <= n; ++i)
        scanf("%d%d%d", &x, &y, &w), maxx = max(maxx, x+1), maxy = max(maxy, y+1), sum[x+1][y+1] += w;
    for (int i = 1; i <= maxx; ++i)
    {
        for (int j = 1; j <= maxy; ++j)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    if (r >= maxx && r >= maxy)
    {
        printf("%d\n", sum[maxx][maxy]);
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= maxx; ++i)
    {
        for (int j = 1; j <= maxy; ++j)
        {
            ans = max(ans, query(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}