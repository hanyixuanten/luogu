// 998
#include <bits/stdc++.h>
using namespace std;
int n, m, ans, t[100005], op[100005];
char str[4];
bool calc(bool x, int j)
{
    for (int i = 0; i < n; i++)
        if (op[i] == 1)
            x |= t[i] >> j & 1;
        else if (op[i] == 2)
            x ^= t[i] >> j & 1;
        else
            x &= t[i] >> j & 1;
    return x;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("\n%s %d", str, t + i);
        if (str[0] == 'O')
            op[i] = 1;
        else if (str[0] == 'X')
            op[i] = 2;
        else
            op[i] = 3;
    }
    for (int i = 29; ~i; i--)
        if (1 << i <= m)
        {
            bool x = calc(0, i), y = calc(1, i);
            if (x >= y)
                ans |= x << i;
            else
                ans |= y << i, m -= 1 << i;
        }
        else
            ans |= calc(0, i) << i;
    printf("%d\n", ans);
    return 0;
}