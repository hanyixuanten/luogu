#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> fri[1505];
int dp[1505][2];
void dfs(int now, int from) {
    dp[now][1] = 1, dp[now][0] = 0;
    for(int i:fri[now]) {
        if(i == from) continue;
        dfs(i, now);
        dp[now][0] += dp[i][1];
        dp[now][1] += min(dp[i][0], dp[i][1]);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0, k, now; i < n; ++i) {
        scanf("%d%d", &now, &k);
        while(k--) {
            int r;
            scanf("%d", &r);
            fri[now].push_back(r);
            fri[r].push_back(now);
        }
    }
    dfs(0, -1);
    printf("%d\n", min(dp[0][0], dp[0][1]));
    return 0;
}