#include <bits/stdc++.h>
using namespace std;
int n, k, type;
int a[100005]; // count
int s[100005]; // to
int f[100005][50];
vector<int> as;
long long res[100005];
long long pow2[50];
int main()
{
    pow2[0] = 1;
    for (int i = 1; i <= 40; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
    }
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &s[i]);
        f[i][0] = s[i];
    }
    for (int l = 1; l <= 40; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][l] = f[f[i][l - 1]][l - 1];
        }
    }
    for (int l = 0; l <= 40; ++l)
    {
        if (k & pow2[l])
            as.push_back(l);
    }
    for (int i = 1; i <= n; ++i)
    {
        int now = i;
        for (int j : as)
        {
            now = f[now][j];
        }
        res[now] += a[i];
    }
    vector<int> ans;
    long long maxx = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (res[i] > maxx)
        {
            ans.clear();
            ans.push_back(i);
            maxx = res[i];
        }
        else if (res[i] == maxx)
            ans.push_back(i);
    }
    printf("%lld\n", maxx);
    if (1)
    {
        for (int i : ans)
        {
            printf("%d ", i);
        }
    }
    return 0;
}