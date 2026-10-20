#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int t, n, a[8005], nxt[8005];
long long f[8005];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int k = i + 1;
            for (int j = 0; j <= i; j++)
                nxt[j] = i + 1;
            for (int j = i - 1; j >= 1; j--) {
                while (k != i + 1 && a[k - 1] != a[j])
                    k = nxt[k];
                if (a[k - 1] == a[j])
                    k--;
                nxt[j] = k;
            }
            for (int j = i - 1; j >= 0; j--)
                if (nxt[j + 1] == i + 1)
                    f[i] = (f[i] + f[j]) % mod;
        }
        printf("%lld\n", f[n]);
        memset(f, 0, sizeof(f[0]) * (n + 1));
    }
    return 0;
}
/*
KMP
ABA.rev = A.rev + B.rev + A.rev
*/