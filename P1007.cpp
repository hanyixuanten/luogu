#include <cstdio>
#include <algorithm>
using namespace std;
int l, n;
int a;
int maxt = 0, mint = 0;
int main()
{
    scanf("%d %d", &l, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        maxt = max(maxt, max(a, l - a + 1)), mint = max(mint, min(a, l - a + 1));
    }
    printf("%d %d\n", mint, maxt);
    return 0;
}