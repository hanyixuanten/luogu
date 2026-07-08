#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[50005];
int ma[50005][20], mi[50005][20];
int main()
{
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        ma[i][0] = a[i], mi[i][0] = a[i];
    }
    for (int j = 1; j < 20; ++j)
    {
        for (int i = 0; i + (1 << (j - 1)) < n; ++i)
        {
            ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        int d = log2(r - l + 1);
        printf("%d\n", max(ma[l][d], ma[r - (1 << d) + 1][d]) - min(mi[l][d], mi[r - (1 << d) + 1][d]));
    }
    return 0;
}