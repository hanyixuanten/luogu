// 125
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int w, s;
} a[50005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].w, &a[i].s);
    sort(a + 1, a + 1 + n, [](node x, node y)
         { return x.w + x.s < y.w + y.s; });
    int tot = 0, ans = -2147483648;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, tot - a[i].s);
        tot += a[i].w;
    }
    printf("%d\n", ans);
    return 0;
}