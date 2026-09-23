#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[100005];
long double f[2][10];
int op;
bitset<100005> b[2][10];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            f[op][j] = f[op ^ 1][j];
            b[op][j] = b[op ^ 1][j];
        }
        if (f[op][a[i] % 10] < a[i])
        {
            f[op][a[i] % 10] = log(a[i]);
            b[op][a[i] % 10].reset();
            b[op][a[i] % 10].set(i);
        }
        for (int j = 0; j < 10; j++)
        {
            if (!f[op ^ 1][j])
            {
                continue;
            }
            int v = j * a[i] % 10;
            if (f[op][v] < f[op ^ 1][j] + log(a[i]))
            {
                f[op][v] = f[op ^ 1][j] + log(a[i]);
                b[op][v] = b[op ^ 1][j];
                b[op][v].set(i);
            }
            else if (f[op][v] == f[op ^ 1][j] + log(a[i]) && b[op ^ 1][j].count() + 1 >= b[op][v].count())
            {
                f[op][v] = f[op ^ 1][j] + log(a[i]);
                b[op][v] = b[op ^ 1][j];
                b[op][v].set(i);
            }
        }
        op ^= 1;
    }
    if (b[op ^ 1][m].none())
    {
        cout << "-1";
    }
    else
    {
        multiset<int> res;
        cout << b[op ^ 1][m].count() << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (b[op ^ 1][m][i])
            {
                res.insert(a[i]);
                // cout << a[i] << ' ';
            }
        }
        for (int i : res)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
