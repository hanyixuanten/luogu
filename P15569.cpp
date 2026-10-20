#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
namespace mat {
struct Mat {
    long long a[3][3];
    int n, m;
    Mat(int _n = 0, int _m = 0) : n(_n), m(_m) { memset(a, 0, sizeof(a)); }
    void operator*=(const Mat &b) {
        if (m != b.n) {
            exit(-1);
        }
        long long res[105][105] = {};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= b.m; ++j) {
                for (int k = 1; k <= m; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= b.m; ++j) {
                a[i][j] = res[i][j];
            }
        }
        m = b.m;
    }
};
Mat qpow(Mat a, long long k) {
    Mat res(a.n, a.n);
    for (int i = 1; i <= a.n; ++i) {
        res.a[i][i] = 1;
    }
    while (k) {
        if (k & 1)
            res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}
long long f(int n) {
    if (n <= 1) {
        return 1;
    }
    Mat base1(1, 2), base2(2, 2);
    base1.a[1][1] = 1;
    base1.a[1][2] = 1;
    base2.a[1][1] = 1;
    base2.a[1][2] = 1;
    base2.a[2][1] = 1;
    base2.a[2][2] = 0;
    base2 = mat::qpow(base2, n - 1);
    base1 *= base2;
    return base1.a[1][1];
}
} // namespace mat
long long qpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
long long ni(int a) { return qpow(a, mod - 2); }
int main() {
    scanf("%d%d", &n, &k);
    if (k < n) {
        printf("0\n");
        return 0;
    }
    long long all = qpow(k, n);
    long long correct = mat::f(n);
    printf("%lld\n", (correct * ni(all)) % mod);
    // printf("%lld\n", mat::f(n + 1));
    return 0;
}
/*
排列
0 <= ai + i - n <= 2
n - i <= ai <= 2 + n - i
只能取 n - i, n - i + 1, n - i + 2 三种
*/