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