#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
bool ma(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i)
    {
        cin >> a[i];
    }
    int t = a[0], c;
    sort(a, a + n * m, ma);
    for (int i = 0; i < n * m; ++i)
    {
        if (a[i] == t)
        {
            c = i;
            break;
        }
    }
    printf("%d %d\n", c / n + 1, ((c / n) % 2) ? n - (c % n) : (c % n) + 1);
    return 0;
}