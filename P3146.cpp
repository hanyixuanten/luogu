#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[250];
int f[250][250]; // l, r
signed main() {
    int ans = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        f[i][i] = a[i];
        ans = max(ans, a[i]);
    }
    for (int len = 2; len <= n; ++len) {
        for (int end = len; end <= n; ++end) {
            int begin = end - len + 1;
            for (int i = begin; i <= end; i++) {
                if (f[begin][i] == f[i + 1][end] && f[begin][i] != 0)
                    f[begin][end] = max(f[begin][end], f[begin][i] + 1);
            }
            ans = max(ans, f[begin][end]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}