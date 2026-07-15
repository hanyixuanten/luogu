#include <bits/stdc++.h>
using namespace std;
int n;
int fa[305];
vector<int> so[305];
int a[305];
bool vis[305];
int de[305];
void dfs(int now, int dep)
{
    vis[now] = 1;
    de[now] = dep;
    for (int i : so[now])
    {
        if (!vis[i])
            dfs(i, dep + 1);
    }
}
int l(int a, int b)
{
    while (de[a] > de[b])
        a = fa[a];
    while (de[a] < de[b])
        b = fa[b];
    while (a != b)
        a = fa[a], b = fa[b];
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> fa[i];
        so[fa[i]].push_back(i);
    }
    dfs(0, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int m;
        cin >> m;
        for (int i = 1; i <= m; ++i)
        {
            cin >> a[i];
        }
        int lca = a[1];
        for (int i = 2; i <= m; ++i)
        {
            lca = l(lca, a[i]);
        }
        int mx = lca;
        while (lca != 0)
        {
            lca = fa[lca];
            mx = max(lca, mx);
        }
        cout << mx << endl;
    }
    return 0;
}