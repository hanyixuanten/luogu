// f[i] = (f[j] = f[nx[i]] && i−nx[i] <= j) ? f[nx[i]] : i;
#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n;
int nxt[N];
int f[N];     // f[i]表示前缀i的答案
int fback[N]; // fback[f[i]]=i
char str[N];
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("5.in", "r", stdin);
#endif
    cin >> str + 1;
    n = strlen(str + 1);
    nxt[0] = -1;
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j != -1 && str[j + 1] != str[i])
            j = nxt[j];
        nxt[i] = ++j;
    }
    f[1] = 1;
    fback[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        
        if (i - nxt[i] <= fback[f[nxt[i]]]) // nx[i]可覆盖
            f[i] = f[nxt[i]];
        else
            f[i] = i;
        fback[f[i]] = i;
    }
    printf("%d\n", f[n]);
    return 0;
}