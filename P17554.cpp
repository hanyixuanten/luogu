#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        while (n % 2 == 0)
            n /= 2;
        while (n % 5 == 0)
            n /= 5;
        int cnt = 0;
        while (n)
        {
            n /= 10, cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}