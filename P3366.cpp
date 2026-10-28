#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int>>> fri;
int fa[5005];
int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        fri.push_back({w, {u, v}});
    }
    sort(fri.begin(), fri.end());
    long long ans = 0;
    for(auto i : fri) {
        if(find(i.second.first) != find(i.second.second)) {
            ans += i.first;
            fa[find(i.second.first)] = find(i.second.second);
        }
    }
    int to = find(1);
    for(int i = 2; i <= n; ++i) {
        if(find(i) != to) {
            printf("orz\n");
            return 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
