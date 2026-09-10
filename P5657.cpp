#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long k;
unsigned long long p2[100];
string gr(int now, unsigned long long k)
{
    if (now == 1)
    {
        if (k == 0)
            return "0";
        else
            return "1";
    }
    if (k < p2[now - 1])
    {
        return "0" + gr(now - 1, k);
    }
    else
    {
        return "1" + gr(now - 1, p2[now] - k - 1);
    }
}
int main()
{
    p2[0] = 1;
    for (int i = 1; i <= 99; ++i)
        p2[i] = p2[i - 1] * 2;
    scanf("%d%llu", &n, &k);
    cout << gr(n, k);
    return 0;
}