// 100
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    long long x = 0, y = 0;
    long long a, pre = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a);
        if (i == 1)
            pre = a;
        long long cha = a - pre;
        if (cha > 0)
            x += cha;
        else
            y -= cha;
        pre = a;
    }
    printf("%lld\n%lld\n", max(x, y), abs(x - y) + 1);
    return 0;
}
/*
1 1 2 2
1 0 1 0
*/