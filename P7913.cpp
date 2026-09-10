#include <bits/stdc++.h>
using namespace std;
int n, m1, m2;
pair<int, int> plane1[100005], plane2[100005];
int f1[100005], f2[100005];
int main()
{
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= m1; i++)
    {
        scanf("%d%d", &plane1[i].first, &plane1[i].second);
    }
    sort(plane1 + 1, plane1 + m1 + 1, [](pair<int, int> x, pair<int, int> y)
         { return x.first < y.first; });
    for (int i = 1; i <= m2; i++)
    {
        scanf("%d%d", &plane2[i].first, &plane2[i].second);
    }
    sort(plane2 + 1, plane2 + m2 + 1, [](pair<int, int> x, pair<int, int> y)
         { return x.first < y.first; });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    priority_queue<int, vector<int>, greater<int>> freeQ;
    for (int i = 1; i <= n; i++)
        freeQ.push(i);
    for (int i = 1; i <= m1; ++i)
    {
        while (!q.empty() && q.top().first <= plane1[i].first)
            freeQ.push(q.top().second), q.pop();
        if (!freeQ.empty())
        {
            q.push({plane1[i].second, freeQ.top()});
            f1[freeQ.top()]++;
            freeQ.pop();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f1[i] += f1[i - 1];
    }
    while (!freeQ.empty())
        freeQ.pop();
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; i++)
        freeQ.push(i);
    for (int i = 1; i <= m2; ++i)
    {
        while (!q.empty() && q.top().first <= plane2[i].first)
            freeQ.push(q.top().second), q.pop();
        if (!freeQ.empty())
        {
            q.push({plane2[i].second, freeQ.top()});
            f2[freeQ.top()]++;
            freeQ.pop();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f2[i] += f2[i - 1];
    }
    int maxres = 0;
    for (int i = 0; i <= n; ++i)
    {
        maxres = max(maxres, f1[i] + f2[n - i]);
    }
    printf("%d\n", maxres);
    return 0;
}