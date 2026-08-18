// 123
#include <bits/stdc++.h>
using namespace std;
int n, x[10005], y[10005], ans = 0, midx, midy;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", x + i, y + i);
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++)
        x[i] -= i;
    sort(x + 1, x + n + 1);
    midx = (n % 2) ? x[n / 2 + 1] : (x[n / 2] + x[n / 2 + 1]) / 2;
    midy = (n % 2) ? y[n / 2 + 1] : (y[n / 2] + y[n / 2 + 1]) / 2;
    for (int i = 1; i <= n; i++)
        ans += abs(x[i] - midx) + abs(y[i] - midy);
    printf("%d\n", ans);
    return 0;
}