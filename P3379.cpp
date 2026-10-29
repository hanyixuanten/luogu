#include<bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> fri[500005];
int dep[500005];
int fa[500005];
int son[500005];
int cnt[500005];
int dfn[500005];
int top[500005];
int nowdfn;
void dfs1(int now, int from) {
    dfn[now] = ++nowdfn;
    cnt[now] = 1;
    dep[now] = dep[fa[now]] + 1;
    for(int i : fri[now]) {
        if(i == from) continue;
        fa[i] = now;
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
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(s, -1);
    dfs2(s, s);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}