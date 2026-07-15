#include <bits/stdc++.h>
using namespace std;
long long ans, n, k;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
int main()
{
    scanf("%lld %lld", &n, &k);
    for (long long i = 1; i <= n; i++)
    {
        long long w;
        scanf("%lld", &w);
        q.push({w, 1});
    }
    while ((q.size() - 1) % (k - 1) != 0)
        q.push({0, 1});
    while (q.size() >= k)
    {
        long long h = -1, w = 0;
        for (long long i = 1; i <= k; ++i)
        {
            pair<long long, long long> t = q.top();
            q.pop();
            h = max(h, t.second), w += t.first;
        }
        ans += w;
        q.push({w, h + 1});
    }
    printf("%lld\n%lld\n", ans, q.top().second - 1);
    return 0;
}