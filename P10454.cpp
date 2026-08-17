// 108
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int tmp[250005];
int c[505][505];
long long ms(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    long long ans = 0;
    ans = ms(l, mid) + ms(mid + 1, r);
    int i = l, j = mid + 1, tot = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
            tmp[tot++] = a[j++], ans += tot - j;
        else
            tmp[tot++] = a[i++];
    }
    while (i <= mid)
        tmp[tot++] = a[i++];
    while (j <= r)
        tmp[tot++] = a[j++];
    for (int i = l; i <= r; ++i)
        a[i] = tmp[i];
    return ans;
}
int main()
{
    while (cin >> n)
    {
        a.clear();
        a.push_back(0);
        memset(tmp, 0, sizeof tmp);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &c[i][j]);
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (c[i][j] != 0)
                        a.push_back(c[i][j]);
                }
            }
            else
            {
                for (int j = n; j >= 1; --j)
                {
                    if (c[i][j] != 0)
                        a.push_back(c[i][j]);
                }
            }
        }
        long long ans1 = ms(1, n * n - 1);
        a.clear();
        a.push_back(0);
        memset(tmp, 0, sizeof tmp);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &c[i][j]);
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (c[i][j] != 0)
                        a.push_back(c[i][j]);
                }
            }
            else
            {
                for (int j = n; j >= 1; --j)
                {
                    if (c[i][j] != 0)
                        a.push_back(c[i][j]);
                }
            }
        }
        long long ans2 = ms(1, n * n - 1);
        if (ans1 % 2 == ans2 % 2)
            puts("TAK");
        else
            puts("NIE");
    }
    return 0;
}