#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> tg[55];
int a[55];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &tg[i].first, &tg[i].second);
    }
    sort(tg, tg + n, [](pair<int, int> a, pair<int, int> b)
         { return a.second - a.first > b.second - b.first; });
    int m = tg[0].second;
    a[0] = tg[0].second;
    for (int i = 1; i < n; i++)
    {
        a[i] = tg[i].second + a[i - 1] - tg[i - 1].second + tg[i - 1].first;
        m = max(m, a[i]);
    }
    printf("%d\n", m);
    return 0;
}