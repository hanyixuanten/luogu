#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<int> fri[100005];
int fa[100005];
int dep[100005];
int top[100005];
int son[100005];
int cnt[100005];
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
    scanf("%d%d", &n, &q);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while(q--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int lca1 = lca(a, b);
        int lca2 = lca(c, d);
        // lca1 在 [c, d] 上或 lca2 在 [a, b] 上
        if(dep[lca2] >= dep[lca1]) {
            if(lca(a, lca2) == lca2 || lca(b, lca2) == lca2) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        } else {
            if(lca(c, lca1) == lca1 || lca(d, lca1) == lca1) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
    }
    return 0;
}
/*
    - deep[x]>=deep[LCA(s,t)]

    - LCA(s,x)=x或LCA(t,x)=x;

*/