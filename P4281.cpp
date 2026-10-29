#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> fri[500005];
int fa[500005];
int dep[500005];
int top[500005];
int son[500005];
int cnt[500005];
void dfs1(int now, int from) {
    cnt[now] = 1;
    for(int i : fri[now]) {
        if(i == from) continue;
        fa[i] = now;
        dep[i] = dep[now] + 1;
        dfs1(i, now);
        cnt[now] += cnt[i];
        if(cnt[son[now]] < cnt[i]) son[now] = i;
    }
}
void dfs2(int now, int from) {
    top[now] = from;
    if(son[now]) dfs2(son[now], from);
    for(int i : fri[now]) {
        if(i == fa[now] || i == son[now]) continue;
        dfs2(i, i);
    }
}
int lca(int a, int b) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    return b;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while(m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int l1 = lca(x, y), l2 = lca(x, z), l3 = lca(y, z);
        int mind = min({dep[l1], dep[l2], dep[l3]});
        int maxd = max({dep[l1], dep[l2], dep[l3]});
        if(l1 == l2)
            printf("%d %d\n", l3, dep[x] + dep[y] + dep[z] - 2 * mind - maxd);
        else if(l1 == l3)
            printf("%d %d\n", l2, dep[x] + dep[y] + dep[z] - 2 * mind - maxd);
        else
            printf("%d %d\n", l1, dep[x] + dep[y] + dep[z] - 2 * mind - maxd);
    }
    return 0;
}