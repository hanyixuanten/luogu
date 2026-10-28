#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, s;
int d[100005];
vector<pair<int, int>> fri[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
signed main() {
    scanf("%lld%lld%lld", &n, &m, &s);
    memset(d, 0x7f, sizeof d);
    d[s] = 0;
    for(int i = 1, u, v, w; i <= m; ++i) {
        scanf("%lld%lld%lld", &u, &v, &w);
        fri[u].push_back({w, v});
    }
    q.push({0, s});
    while(!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        if (now.first != d[now.second]) continue;
        for(pair<int, int> to:fri[now.second]) {
            if(d[to.second] > d[now.second] + to.first) {
                d[to.second] = d[now.second] + to.first;
                q.push({d[to.second], to.second});
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%lld ", d[i]);
    }
    return 0;
}