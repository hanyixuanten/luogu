#include<bits/stdc++.h>
using namespace std;
const int mod = 19650827;
int n;
int a[1005];
int f[1005][1005];
int g[1005][1005];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i][i] = 1;
        // g[i][i] = 1;
    }
    for(int len = 1; len < n; ++len) {
        for(int l = 1; l + len <= n; ++l) {
            int r = l + len;
            f[l][r] = (f[l + 1][r] * (a[l] < a[l + 1]) + g[l + 1][r] * (a[l] < a[r])) % mod;
            g[l][r] = (f[l][r - 1] * (a[l] < a[r]) + g[l][r - 1] * (a[r - 1] < a[r])) % mod;
        }
    }
    printf("%d\n", (f[1][n] + g[1][n]) % mod);
    return 0;
}