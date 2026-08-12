#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
    int x, y, z, id;
} star[100005];
bool cmpx(node a, node b)
{
    return a.x < b.x;
}
bool cmpy(node a, node b)
{
    return a.y < b.y;
}
bool cmpz(node a, node b)
{
    return a.z < b.z;
}
struct edge
{
    int u, v, w;
    const bool operator<(const edge b) const
    {
        return w < b.w;
    }
} gra[500005];
int tot;
int fa[100005];
int find(int now)
{
    if (fa[now] == now)
        return now;
    return fa[now] = find(fa[now]);
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%lld", &star[i].x, &star[i].y, &star[i].z);
        fa[i] = i;
        star[i].id = i;
    }
    sort(star + 1, star + n + 1, cmpx);
    for (int i = 1; i < n; ++i)
    {
        gra[tot].u = star[i].id;
        gra[tot].v = star[i + 1].id;
        gra[tot++].w = abs(star[i].x - star[i + 1].x);
    }
    sort(star + 1, star + n + 1, cmpy);
    for (int i = 1; i < n; ++i)
    {
        gra[tot].u = star[i].id;
        gra[tot].v = star[i + 1].id;
        gra[tot++].w = abs(star[i].y - star[i + 1].y);
    }
    sort(star + 1, star + n + 1, cmpz);
    for (int i = 1; i < n; ++i)
    {
        gra[tot].u = star[i].id;
        gra[tot].v = star[i + 1].id;
        gra[tot++].w = abs(star[i].z - star[i + 1].z);
    }
    sort(gra, gra + tot);
    int cnt = 0, num = 0;
    for (int i = 0; i < tot && cnt < n - 1; ++i)
    {
        int fu = find(gra[i].u);
        int fv = find(gra[i].v);

        if (fu != fv)
        {
            fa[fu] = fv; // 必须合并根节点
            ++cnt;
            num += gra[i].w;
        }
    }
    printf("%lld\n", num);
    return 0;
}