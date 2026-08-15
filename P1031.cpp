#include <cstdio>
using namespace std;
int a[105];
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int avg = sum / n, ans = 0, pre = 0;
    for (int i = 1; i < n; ++i)
    {
        pre += a[i] - avg;
        if (pre != 0)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}