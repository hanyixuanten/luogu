// 101
#include <bits/stdc++.h>
using namespace std;
int n, p, h, m;
int cha[5005];
set<pair<int, int>> can;
int main()
{
    scanf("%d%d%d%d", &n, &p, &h, &m);
    for (int a, b, i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        can.insert({a, b});
    }
    cha[1] = h;
    cha[n + 1] = -h;
    for (pair<int, int> k : can)
    {
        cha[k.first + 1]--;
        cha[k.second]++;
    }
    int now = cha[0];
    for (int i = 1; i <= n; ++i)
    {
        now += cha[i];
        printf("%d\n", now);
    }
    return 0;
}