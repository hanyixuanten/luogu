// 104
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int mid = (n % 2) ? a[n + 1 >> 1] : (a[n >> 1] + a[(n >> 1) + 1]) >> 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += abs(a[i] - mid);
    }
    printf("%d\n", ans);
    return 0;
}