#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> edge[200005];
bool vis[200005];
int de[200005];
void dfs(int now, int dep)
{
    de[now] = dep;
    vis[now] = 1;
    for (auto i : edge[now])
    {
        if (!vis[i])
            dfs(i, dep + 1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    int l1 = 0, l2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (de[i] % 2)
            l1++;
        else
            l2++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (de[i] % 2)
            printf("%d ", l1);
        else
            printf("%d ", l2);
    }
    return 0;
}