#include<bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> fri[500005];
int fa[500005][25];
int dep[500005];
void dfs(int now, int from = -1) {
    for(int i = 1; i <= 24; ++i) {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    for(int i : fri[now]) {
        if(i == from) continue;
        dep[i] = dep[now] + 1;
        fa[i][0] = now;
        dfs(i, now);
    }
}
int lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 24; i >= 0 && dep[a] > dep[b]; --i) {
        if(a == b) return a;
        if(dep[fa[a][i]] >= dep[b] && dep[a] >= (1 << i)) a = fa[a][i];
        if(a == b) return a;
    }
    if(a == b) return a;
    for(int i = 24; i >= 0; --i) {
        if(fa[a][i] != fa[b][i] && dep[a] >= (1 << i)) a = fa[a][i], b = fa[b][i];
    }
    if(a != b) a = fa[a][0];
    return a;
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs(s);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}