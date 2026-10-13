#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
int a[200005];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        if (k == 1) {
            if (a[1] == 1)
                printf("-1\n");
            else
                printf("0\n");
            continue;
        }
        long long ans = 0;
        int exp = 1;
        for (int i = 1; i <= n && a[i] <= k; i++)
            if (a[i] == k)
                ans++, a[i]--;
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= exp) {
                ans += a[i] - exp, exp++;
                if (exp == k) {
                    printf("%lld\n", ans);
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag) {
            printf("-1\n");
            continue;
        }
    }
    return 0;
}