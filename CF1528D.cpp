#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> fri[605];
long long dis[605];
bitset<605> vis;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        fri[u].push_back({v, t});
    }
    for (int st = 0; st < n; ++st) {
        memset(dis, 0x3f, sizeof(dis));
        vis.reset();
        for (auto [v, w] : fri[st])
            dis[v] = min(dis[v], (long long) w);
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            for (int j = 0; j < n; j++)
                if (!vis[j] && (u == -1 || dis[j] < dis[u]))
                    u = j;
            vis[u] = 1;
            int v = (u + 1) % n;
            dis[v] = min(dis[v], dis[u] + 1);
            int r = dis[u] % n;
            for (auto [v, w] : fri[u])
            {
                v = (v + r) % n;
                dis[v] = min(dis[v], dis[u] + w);
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d ", (i == st) ? 0 : dis[i]);
        printf("\n");
    }
    return 0;
}