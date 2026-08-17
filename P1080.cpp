// 114
#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> lr[1005];
struct gjd
{
    int a[4005], len;
    void operator=(int rhs)
    {
        len = 0;
        if (rhs == 0)
        {
            len = 1;
            return;
        }
        while (rhs)
            a[++len] = rhs % 10000, rhs /= 10000;
        return;
    }
    void operator=(const gjd rhs)
    {
        memcpy(a, rhs.a, sizeof(rhs.a));
        len = rhs.len;
        return;
    }
    void operator*=(const int rhs)
    {
        for (int i = 1; i <= len; i++)
            a[i] *= rhs;
        for (int i = 1; i <= len; i++)
        {
            a[i + 1] += a[i] / 10000, a[i] %= 10000;
            if (i + 1 > len && a[i + 1])
                len++;
        }
        while (len && a[len] == 0)
            len--;
    }
    gjd operator/(const int rhs)
    {
        gjd c;
        c = *this;
        while (c.len && c.a[c.len] == 0)
            c.len--;
        for (int i = c.len; i; i--)
        {
            c.a[i - 1] += (c.a[i] % rhs) * 10000;
            c.a[i] /= rhs;
        }
        while (c.len && c.a[c.len] == 0)
            c.len--;
        return c;
    }
    void print()
    {
        while (len && a[len] == 0)
            len--;
        if (len == 0)
        {
            putchar('0');
            return;
        }
        printf("%d", a[len]);
        for (int i = len - 1; i; i--)
            printf("%04d", a[i]);
    }
    bool operator>(const gjd &rhs) const
    {
        if (len != rhs.len)
            return len > rhs.len;
        for (int i = len; i; i--)
            if (a[i] != rhs.a[i])
                return a[i] > rhs.a[i];
        return 0;
    }
} ma, now, tmp;

int main()
{

    scanf("%d%d%d", &n, &lr[0].first, &lr[0].second);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &lr[i].first, &lr[i].second);
    sort(lr + 1, lr + n + 1, [](pair<int, int> x, pair<int, int> y)
         { return x.first * x.second < y.first * y.second; });
    now = lr[0].first;
    for (int i = 1; i <= n; ++i)
    {
        tmp = now / lr[i].second;
        if (tmp > ma)
            ma = tmp;
        now *= lr[i].first;
    }
    ma.print();
    return 0;
}