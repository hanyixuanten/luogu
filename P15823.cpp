#include<bits/stdc++.h>
using namespace std;
int n, p, q;
int a[2005];
int f[2005][2005];
bool check(int w) {
    for(int i = 0; i <= p; ++i) {
        for(int j = 1; j <= n; ++j) {
            f[i][j] = 0x7f7f7f7f;
        }
    }
    for(int i = 1; i <= n; ++i) {
        int s = upper_bound(a + 1, a + n + 1, a[i] - w) - a - 1;
        int t = upper_bound(a + 1, a + n + 1, a[i] - 2 * w) - a - 1;
        f[0][i] = f[0][t] + 1;
        for(int j = 1; j <= p; ++j) {
            f[j][i] = min(f[j - 1][s], f[j][t] + 1);
        }
    }
    return f[p][n] <= q;
}
int main() {
    scanf("%d%d%d", &n, &p, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    if (p + q >= n)
    { // 若总数足够多，一个盯一个即可，固以下计算 p + q < 2000
        printf("1\n");
        return 0;
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = 1e9;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
/*
f i, k为仅用 i 个小区间处理完前 k 个点所用最少的大区间个数。


f{i, k} = min(f{i − 1, s}, f{i, t} + 1)
*/