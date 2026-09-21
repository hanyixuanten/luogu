#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];
int spf[100005]; // 最小质因子
vector<int> fac[100005]; // 每个数的质因子列表（带重数）
int cnt[100005]; // 当前窗口内每个质数的总指数
long long cur, ans;
deque<int> dq_max, dq_min;
// 计算e的贡献
long long gx(int e) {
    if (e == 0) return 0;
    long long t = (sqrt(8.0 * e + 1) - 1) / 2;
    while ((t + 1) * (t + 2) / 2 <= e) ++t;
    while (t * (t + 1) / 2 > e) --t;
    return e + t;
}
// 预处理最小质因子
void init_spf() {
    for (int i = 2; i < 100005; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            if ((long long)i * i < 100005) {
                for (int j = i * i; j < 100005; j += i) {
                    if (!spf[j]) spf[j] = i;
                }
            }
        }
    }
}
// 分解质因数
void get_fac(int idx, int x) {
    while (x > 1) {
        int p = spf[x];
        while (x % p == 0) {
            fac[idx].push_back(p);
            x /= p;
        }
    }
}
int main() {
    scanf("%d%d", &n, &k);
    init_spf();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        get_fac(i, a[i]);
    }
    int l = 1;
    cur = 0,ans = 0;
    for (int r = 1; r <= n; ++r) {
        // 加入 a[r]
        for (int p : fac[r]) {
            int e = cnt[p];
            cur += gx(e + 1) - gx(e);
            cnt[p]++;
        }
        while (!dq_max.empty() && a[dq_max.back()] <= a[r]) dq_max.pop_back();
        dq_max.push_back(r);
        while (!dq_min.empty() && a[dq_min.back()] >= a[r]) dq_min.pop_back();
        dq_min.push_back(r);
        // 收缩左边界
        while (1) {
            while (!dq_max.empty() && dq_max.front() < l) dq_max.pop_front();
            while (!dq_min.empty() && dq_min.front() < l) dq_min.pop_front();
            int mx = a[dq_max.front()];
            int mn = a[dq_min.front()];
            if (mx - mn <= k) break;
            // 移除 a[l]
            for (int p : fac[l]) {
                int e = cnt[p];
                cur += gx(e - 1) - gx(e);
                cnt[p]--;
            }
            l++;
        }
        ans = max(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}