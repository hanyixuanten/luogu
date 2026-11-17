#include <bits/stdc++.h>
using namespace std;
int n;
long long bk[100005];
long long d[100005];
long long s[100005];
int px[100005];
vector<int> fri[100005];
int dep[100005];
long long ans = 0;
void dfs(int now, int from) {
    for (int i : fri[now]) {
        if(i == from) continue;
        dep[i] = dep[now] + 1;
        ans += dep[i];
        dfs(i, now);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &bk[i]);
        d[i] = bk[i];
        s[i] = 1;
    }
    vector<pair<long long, int>> a;
    for (int i = 1; i <= n; ++i) {
        a.push_back({d[i], i});
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) {
        d[i] = a[i - 1].first;
        px[i] = a[i - 1].second;
    }
    for (int i = n; i > 1; --i) {
        long long fi = d[i] + 2LL * s[i] - n;
        int to = lower_bound(d + 1, d + i, fi) - d;
        if (to >= i || d[to] != fi) {
            printf("-1\n");
            return 0;
        }
        fri[to].push_back(i);
        s[to] += s[i];
    }
    if (s[1] != n) {
        printf("-1\n");
        return 0;
    }
    dfs(1, 0);
    if(ans != d[1]) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : fri[i]) {
            printf("%d %d\n", px[i], px[j]);
        }
    }
    return 0;
}
