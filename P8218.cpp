#include <cstdio>
using namespace std;
int n, m;
int a[100005], pre[100005];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        pre[i] = a[i] + pre[i - 1];
    }
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", pre[r] - pre[l - 1]);
    }
    return 0;
}