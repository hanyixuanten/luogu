#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

struct Mat {
    long long a[105][105];
    int n, m;

    Mat(int _n = 0, int _m = 0) : n(_n), m(_m) {
        memset(a, 0, sizeof(a));
    }

    void operator*=(const Mat &b) {
        if (m != b.n) {
            cerr << "矩阵维度不匹配" << endl;
            exit(-1);
        }
        long long res[105][105] = {};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= b.m; ++j) {
                for (int k = 1; k <= m; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * b.a[k][j]) % MOD;
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
        if (k & 1) res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}

int main() {
    long long n;
    scanf("%lld", &n);

    if (n <= 2) {
        printf("1\n");
        return 0;
    }

    Mat base1(1, 2), base2(2, 2);

    base1.a[1][1] = 1;
    base1.a[1][2] = 1;
    base2.a[1][1] = 1;
    base2.a[1][2] = 1;
    base2.a[2][1] = 1;
    base2.a[2][2] = 0;
    base2 = qpow(base2, n - 2);
    base1 *= base2;
    printf("%lld\n", base1.a[1][1]);
    return 0;
}