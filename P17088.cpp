#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main()
{
    scanf("%lld", &n);
    int ans = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        ans <<= 1;
        ans += 1;
    }
    for (int i = 0; i < n / 2; ++i)
    {
        ans <<= 1;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
5
00000
末尾0的个数等于1的个数
*/