#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[100005];
int mi[100005][20];
int main()
{
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        mi[i][0] = a[i];
    }
    for (int j = 1; j < 20; ++j)
    {
        for (int i = 0; i + (1 << (j - 1)) < n; ++i)
        {
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        int d = log2(r - l + 1);
        printf("%d ", min(mi[l][d], mi[r - (1 << d) + 1][d]));
    }
    return 0;
}