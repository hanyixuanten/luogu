#include <bits/stdc++.h>
using namespace std;
int n;
char op[105];
long long a[105];
long long f[105][105];
long long g[105][105];
void getc(char &c) {
    c = getchar_unlocked();
    while(c != 't' && c != 'x') c = getchar_unlocked();
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        getc(op[i]);
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
        op[i + n] = op[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        f[i][i] = a[i];
        g[i][i] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= 2 * n; ++l) {
            int r = l + len - 1;
            f[l][r] = LLONG_MIN;
            g[l][r] = LLONG_MAX;
            for (int k = l; k < r; ++k) {
                char o = op[k + 1];
                if (o == 't') {
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r]);
                } else {
                    long long v1 = f[l][k] * f[k + 1][r];
                    long long v2 = f[l][k] * g[k + 1][r];
                    long long v3 = g[l][k] * f[k + 1][r];
                    long long v4 = g[l][k] * g[k + 1][r];
                    f[l][r] = max({f[l][r], v1, v2, v3, v4});
                    g[l][r] = min({g[l][r], v1, v2, v3, v4});
                }
            }
        }
    }
    long long ans = LLONG_MIN;
    vector<int> anss;
    for (int l = 1; l <= n; ++l) {
        int r = l + n - 1;
        // printf("%lld\n", f[l][r]);
        if (f[l][r] > ans) {
            ans = f[l][r];
            anss.clear();
            anss.push_back(l);
        } else if(f[l][r] == ans) {
            anss.push_back(l);
        }
    }
    printf("%lld\n", ans);
    for(int i:anss) printf("%d ", i);
    return 0;
}