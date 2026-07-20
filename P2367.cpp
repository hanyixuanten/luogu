#include <bits/stdc++.h>
using namespace std;
int n, p;
int a[5000005];
int cha[5000005];
int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        cha[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= p; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        cha[x] += z;
        cha[y + 1] -= z;
    }
    int minn = cha[1];
    a[1] = cha[1];
    for (int i = 2; i <= n; ++i)
    {
        a[i] = a[i - 1] + cha[i];
        minn = min(a[i], minn);
    }
    printf("%d\n", minn);
    return 0;
}