#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
int a[100005];
int mod[100005][11];
int ks[100005][11];
signed main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        mod[i][0] = a[i] % k;
        ks[mod[i][0]][0]++;
        for (int j = 1; j <= 10; ++j) {
            mod[i][j] = (mod[i][j - 1] * 10) % k;
            ks[mod[i][j]][j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) { // 作为底部
        int len, now = a[i];
        for (len = 0; now; len++, now /= 10)
            ;
        int want = (k - mod[i][0]) % k;
        ans += ks[want][len];
        if (mod[i][len] == want)
            ans--;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
计算 *10^i mod k
*/