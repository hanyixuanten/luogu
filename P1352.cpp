#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int r[10000];
int fa[10000];
int f[10000][2];
vector<int> chi[10000];
int dp(int now, bool choose) // 现在到哪个节点且父亲是否取
{
    if (f[now][choose])
        return f[now][choose];
    if (choose)
    {
        int ans = 0;
        for (auto k : chi[now])
        {
            ans += dp(k, 0);
        }
        f[now][choose] = ans;
        return ans;
    }
    int ans1 = 0, ans2 = 0;
    for (auto k : chi[now])
        ans1 += dp(k, 0);
    for (auto k : chi[now])
        ans2 += dp(k, 1);
    f[now][choose] = max(ans1, ans2 + r[now]);
    return f[now][choose];
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &r[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        fa[u] = v;
        chi[v].push_back(u);
    }
    int root = 1;
    while (fa[root])
        root = fa[root];
    printf("%lld\n", dp(root, 0));
    return 0;
}