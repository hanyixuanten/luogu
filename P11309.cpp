#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n, k;
int a[100005];
long long calc() {
    long long ans = 0;
    int nowmax = 0;
    for (int i = 1; i <= n; ++i) {
        nowmax = max(a[i], nowmax), ans += nowmax;
    }
    return ans;
}
signed main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        int ma = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]), ma = max(ma, a[i]);
        }
        if (k == 0)
            printf("%lld\n", calc());
        else if (n == 2) {
            if (k % 2 == 1)
                swap(a[1], a[2]);
            printf("%lld\n", a[1] + max(a[1], a[2]));
        } else
            printf("%lld\n", 1ll * n * ma);
    }
    return 0;
}