#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool vis[510][25];
int n, m, k;
vector<int> g[510];
void dfs(int now, int dep)
{
    if (vis[now][dep])
        return;
    vis[now][dep] = 1;
    if (dep == k)
        return;
    for (int i = 0; i < g[now].size(); i++)
        dfs(g[now][i], dep + 1);
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int j = 0; j < m; j++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        dfs(i, 0);
        for (int dep = 1; dep <= k; dep++)
        {
            int ans = 0;
            for (int now = 1; now <= n; now++)
                ans += vis[now][dep];
            printf("%d ", ans);
        }
        printf("\n");
    }
    return 0;
}
