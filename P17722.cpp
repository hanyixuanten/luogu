#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[1000005];
int c[1000005];
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, l; i <= m; ++i) {
        scanf("%lld", &l);
        int sum = 0;
        for (int j = 1, x; j <= l; ++j) {
            scanf("%lld", &x);
            int pos = lower_bound(a + 1, a + n + 1, x) - a - 1;
            sum += n - pos;
        }
        c[i] = sum;
    }
    sort(c + 1, c + m + 1);
    int ans = m * n * (n + 1) / 2;
    for (int k = 1; k <= m; ++k) {
        ans += c[k] * (m - k + 1);
    }
    printf("%lld\n", ans);
    return 0;
}