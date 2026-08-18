#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> fri[500005];
bool vis[500005];
vector<int> cc;
void dfs(int now)
{
    vis[now] = 1;
    cc.push_back(now);
    for (auto k : fri[now])
    {
        if (!vis[k])
            dfs(k);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(fri[i].begin(), fri[i].end());
    }
    dfs(1);
    for (auto k : cc)
        printf("%d ", k);
    return 0;
}