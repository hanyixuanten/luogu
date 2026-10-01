#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    printf("Yes\n");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", 3 * (i - 1));
    }
    printf("\n");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", 3 * (i - 1) + 1);
    }
    return 0;
}
/*


a相邻两项mod3n的值
ab同一项mod3n的值
b,b+kmod 3n的值
*/