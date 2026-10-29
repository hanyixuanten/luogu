#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> fri[100005];
int cnt[100005];
int fa[100005];
int son[100005];
int dfn[100005];
int top[100005];
int dep[100005];
int nowdfn;
int ans[100005];
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
    dfn[now] = ++nowdfn;
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
void dfsadd(int now, int from) {
    for(int i : fri[now]) {
        if(i == from) continue;
        dfsadd(i, now);
        ans[now] += ans[i];
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, 1);
    while(k--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int w = lca(u, v);
        ans[u]++;
        ans[v]++;
        ans[w]--;
        if(fa[w]) ans[fa[w]]--;
    }
    dfsadd(1, -1);
    int maxans = 0;
    for(int i = 1; i <= n; ++i) maxans = max(maxans, ans[i]);
    printf("%d\n", maxans);
    return 0;
}