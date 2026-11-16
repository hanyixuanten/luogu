#include <bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000000000ll;

int n, m, q;
vector<pair<long long, int>> fri[200005];
long long dis[200005];
bool vis[200005];

priority_queue<pair<long long, int>> pq;

int main()
{
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1, o; i <= n; ++i)
    {
        scanf("%d", &o);
        if (o)
        {
            dis[i] = inf;
            pq.push({dis[i], i});
        }
    }

    for (int i = 1, u, v; i <= m; ++i)
    {
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        fri[u].push_back({w, v});
        fri[v].push_back({w, u});
    }

    while (!pq.empty())
    {
        pair<long long, int> now = pq.top();
        pq.pop();

        int u = now.second;
        if (vis[u]) continue;
        vis[u] = 1;

        for (pair<long long, int> to : fri[u])
        {
            long long w = to.first;
            int v = to.second;

            if (dis[v] >= dis[u]) continue;

            dis[v] = min(dis[u], dis[v] + w);
            pq.push({dis[v], v});
        }
    }

    while (q--)
    {
        int s;
        long long k;
        scanf("%d%lld", &s, &k);

        if (dis[s] >= k)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}