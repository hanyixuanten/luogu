# AT_agc013_e

[luoshunran](https://www.acwing.com/file_system/file/content/whole/index/content/14321537/)

## 20 pts O(n)

把正方形的交界处看作隔板，在每两个隔板之间放入一黑一白两个球，正方形的大小也就等于区间内放入两个球的方案数，正方形的面积的乘积就是所有的放球方案乘法原理乘起来。于是变成了求有多少种放隔板、放球的方案。

做 dp $f(i, 0/1/2)$，代表目前这个区间内放入了几个球的方案。

注意 $f(1, 1) = 2$

若 $i - i + 1$ 之间可以放隔板，

- $f(i+1, 0) = f(i, 0) + f(i, 2)$
- $ f(i+1, 1) = 2 * f(i, 0) + f(i, 1) + 2 * f(i, 2)$, 这里乘以 2 代表决策放入的是黑球还是白球
- $ f(i+1, 2) = f(i, 0) + f(i, 1) + 2 * f(i, 2) $

类似地，也可以列出不可以放隔板的情况。

- $f(i+1, 0) = f(i, 0)$
- $f(i+1, 1) = 2 * f(i, 0) + f(i, 1)$
- $f(i+1, 2) = f(i, 0) + f(i, 1) + f(i, 2)$

```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
long long f[5000005][3];
int a[100005];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);
    int tot = 1;
    f[1][0] = 1, f[1][1] = 2, f[1][2] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (i == a[tot])
        {
            tot++;
            f[i + 1][0] = f[i][0];
            f[i + 1][1] = (f[i][0] * 2 + f[i][1]) % mod;
            f[i + 1][2] = (f[i][0] + f[i][1] + f[i][2]) % mod;
        }
        else
        {
            f[i + 1][0] = (f[i][0] + f[i][2]) % mod;
            f[i + 1][1] = (f[i][0] * 2 + f[i][1] + 2 * f[i][2]) % mod;
            f[i + 1][2] = (f[i][0] + f[i][1] + f[i][2] * 2) % mod;
        }
    }
    printf("%lld\n", f[n][2]);
    return 0;
}
```

## 100 pts O(m log n)

注意到一个区间内需要多次转移，非常浪费。可以考虑使用矩阵快速幂优化。

对于非标记点，转移矩阵为：

$$
T=\begin{bmatrix}
    1&0&1\\
    2&1&2\\
    1&1&2
\end{bmatrix}
$$

对于标记点：

$$
T=\begin{bmatrix}
    1&0&0\\
    2&1&0\\
    1&1&1
\end{bmatrix}
$$

初始位置矩阵为：

$$
T=\begin{bmatrix}
    1\\
    2\\
    1
\end{bmatrix}
$$

矩阵快速幂代码可参考[P1962](https://luogu.com.cn/problem/P1962)

```cpp
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
```

最终程序：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
int a[100005];
const long long fir[4][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 1}};
const long long yes[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 2, 1, 0}, {0, 1, 1, 1}};
const long long no[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 1}, {0, 2, 1, 2}, {0, 1, 1, 2}};
struct Mat
{
    long long a[5][5] = {};
    int n, m;
    Mat(int _n = 0, int _m = 0, int cpy = 0) : n(_n), m(_m)
    {
        if (cpy == 1)
            for (int i = 1; i <= 3; ++i)
                a[i][1] = fir[i][1];
        else if (cpy == 2)
            for (int i = 1; i <= 3; ++i)
                for (int j = 1; j <= 3; ++j)
                    a[i][j] = yes[i][j];
        else if (cpy == 3)
            for (int i = 1; i <= 3; ++i)
                for (int j = 1; j <= 3; ++j)
                    a[i][j] = no[i][j];
    }
    void operator*=(const Mat &b)
    {
        if (m != b.n)
            exit(-1);
        long long res[5][5] = {};
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                for (int k = 1; k <= m; ++k)
                    res[i][j] = (res[i][j] + a[i][k] * b.a[k][j]) % mod;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                a[i][j] = res[i][j];
        m = b.m;
    }
    Mat operator*(const Mat &b)
    {
        if (m != b.n)
            exit(-1);
        Mat res(n, b.m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                for (int k = 1; k <= m; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
};

Mat qpow(Mat a, long long k)
{
    Mat res(a.n, a.n);
    for (int i = 1; i <= a.n; ++i)
        res.a[i][i] = 1;
    while (k)
    {
        if (k & 1)
            res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}
Mat yess(3, 3, 2);
Mat noo(3, 3, 3);

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    Mat now(3, 1, 1);
    int pos = 1;
    for (int i = 1; i <= m; ++i)
    {
        int x = a[i];
        if (x < pos)
            continue;
        if (x > pos)
        {
            now = qpow(noo, x - pos) * now;
        }
        {
            now = yess * now;
        }
        pos = x + 1;
    }
    if (n - pos > 0)
    {
        now = qpow(noo, n - pos) * now;
    }
    printf("%lld\n", now.a[3][1]);
    return 0;
}
```
