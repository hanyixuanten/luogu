// 110
#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> s[2505];
pair<int, int> spf[2505];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &s[i].first, &s[i].second); // min max
    sort(s + 1, s + n + 1, [](pair<int, int> x, pair<int, int> y)
         { return x.second > y.second; }); // 按 max 降序
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &spf[i].first, &spf[i].second);
    sort(spf + 1, spf + m + 1, [](pair<int, int> x, pair<int, int> y)
         { return x.first > y.first; }); // 按 spf 降序

    int point = 1;
    priority_queue<pair<int, int>> q; // 按 min 降序
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (point <= n && s[point].second >= spf[i].first)
            q.push(s[point++]);
        while (!q.empty() && q.top().first > spf[i].first)
            q.pop();
        while (!q.empty() && spf[i].second > 0)
            q.pop(), spf[i].second--, ans++;
    }
    printf("%d\n", ans);
    return 0;
}