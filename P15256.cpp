#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<ll> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &a[i]);
    }
    const int MAXI = 31;
    vector<ll> dp(MAXI + 2, 0);
    dp[1] = a[1];
    for (int i = 2; i <= MAXI; ++i) {
        if (i <= N)
            dp[i] = min(a[i], 2 * dp[i - 1]);
        else
            dp[i] = 2 * dp[i - 1];
    }

    while (Q--) {
        ll x;
        scanf("%lld", &x);
        ll ans = LLONG_MAX;
        ll cur_cost = 0;
        bool tight = true;
        for (int i = 30; i >= 0; --i) {
            if (tight) {
                if ((x >> i) & 1LL) {
                    cur_cost += dp[i + 1];
                } else {
                    ans = min(ans, cur_cost + dp[i + 1]);
                }
            } else {
                break;
            }
        }
        ans = min(ans, cur_cost);
        printf("%lld\n", ans);
    }
    return 0;
}