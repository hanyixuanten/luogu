#include <bits/stdc++.h>
using namespace std;
int n;
int aa[10];
bool pd(int now)
{
    for (int i = 1; i <= n; ++i)
    {
        int acpy = aa[i];
        int pp = 0;
        int cha = 0;
        int ncpy = now;
        int xl = 0;
        for (int j = 1; j <= 5; ++j)
        {
            if (acpy % 10 != ncpy % 10)
            {
                pp++;

                if (pp == 1)
                    cha = ((acpy % 10 - ncpy % 10) + 10) % 10, xl = j;
                
                else if (((acpy % 10 - ncpy % 10) + 10) % 10 != cha || abs(j - xl) != 1) return 0;
            }
            acpy /= 10, ncpy /= 10;
        }
        if (pp > 2 || pp == 0)
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        aa[i] = 10000 * a + 1000 * b + 100 * c + 10 * d + e;
    }
    int ans = 0;
    for (int i = 0; i <= 99999; i++)
    {
        if (pd(i))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}