#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> fri[5005];
int fa[5005];
int cnt[5005];
bitset<5005> canc;
long long anss = 0;
void dfs0(int now) {
    cnt[now] = 1;
    for(int i : fri[now]) {
        if(i == fa[now]) continue;
        fa[i] = now;
        dfs0(i);
        cnt[now] += cnt[i];
    }
}
void dp(int now) {
    vector<int> chi(1, 0);
    for(int i : fri[now]) {
        if(i == fa[now]) continue;
        dp(i);
        chi.push_back(i);
    }
    int sum = 0;
    canc.reset();
    for(int i = 1; i < (int)chi.size(); ++i) {
        sum += cnt[chi[i]];
        canc[sum] = 1;
        for(int j = sum; j >= cnt[chi[i]]; --j)
            if(canc[j - cnt[chi[i]]]) canc[j] = 1;
        for (int j = cnt[chi[i]]; j <= sum; j++)
            if(canc[j]) canc[sum - j] = 1;
    }
    long long ans = 0;
    for(int i = 1; i < cnt[now]; ++i) {
        if(canc[i])
            ans = max(ans, (cnt[now] - 1ll - i) * i);
    }
    anss += ans;
}
int main() {
    scanf("%d", &n);
    for(int i = 2, v; i <= n; ++i) {
        scanf("%d", &v);
        fri[i].push_back(v);
        fri[v].push_back(i);
    }
    dfs0(1);
    dp(1);
    printf("%lld\n", anss);
    return 0;
}