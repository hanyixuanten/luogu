#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> fri[30005];
bitset<30005> to[30005];
bitset<30005> vis;
void dfs(int now) {
    vis[now] = 1;
    for(int i : fri[now]) {
        if(!vis[i]) dfs(i);
        to[now] |= to[i];
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        fri[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i) to[i][i] = 1;
    for(int i = 1; i <= n; ++i) {
        dfs(i);
        printf("%d\n", to[i].count());
    }
    return 0;
}