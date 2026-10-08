#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, p[1000005];
signed main() {
    scanf("%lld%lld%lld", &n, &k, &p[1]);
    for (int i = 2; i <= k; ++i)
        p[i] = p[i - 1] + ((p[i - 1] * 7ll + 7) % 10) + 1;
    sort(p + 1, p + k + 1);
    int ans = 0;
    for (int l = 1, r = p[k] - p[1], mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
        int cnt = 1, lst = p[1];
        for (int i = 2; i <= k && cnt < n; ++i)
            if (p[i] - lst >= mid)
                ++cnt, lst = p[i];
        if (cnt >= n)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}