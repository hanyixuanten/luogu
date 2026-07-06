#include <cstdio>
using namespace std;
int n;
int x1[10005], y1[10005], x2[10005], y2[10005];
int main()
{
    scanf("%d", &n);
    for (int c = 1; c <= n; c++)
    {
        int x, y, lx, ly;
        scanf("%d %d %d %d", &x, &y, &lx, &ly);
        x1[c] = x, x2[c] = x + lx, y1[c] = y, y2[c] = y + ly;
    }
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = n; i >= 1; i--)
    {
        if (x >= x1[i] && x <= x2[i] && y >= y1[i] && y <= y2[i])
        {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}