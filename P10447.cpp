// 91
#include <bits/stdc++.h>
using namespace std;
int f[2100000][21], w[2100000][21];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);
    memset(f, 0x7f, sizeof f);
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}