// 127
#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> rob[100005], task[100005];
int c[105];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &rob[i].first, &rob[i].second);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &task[i].first, &task[i].second);
    sort(rob + 1, rob + n + 1, [](pair<int, int> a, pair<int, int> b)
         { return (a.first == b.first) ? a.second > b.second : a.first > b.first; });
    sort(task + 1, task + m + 1, [](pair<int, int> a, pair<int, int> b)
         { return (a.first == b.first) ? a.second > b.second : a.first > b.first; });
    int p = 0;
    int cnt = 0;
    long long ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (p < n && rob[p + 1].first >= task[i].first)
            p++, c[rob[p].second]++;
        for (int j = task[i].second; j <= 100; j++)
            if (c[j])
            {
                cnt++, c[j]--, ans += task[i].first * 500 + task[i].second * 2;
                break;
            }
    }
    printf("%d %lld\n", cnt, ans);
    return 0;
}