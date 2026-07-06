#include <cstdio>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    int a;
    for (a = 1; a * (a + 1) / 2 < n; ++a)
        ;
    int c = a * (a + 1) / 2 - n;
    if (a % 2)
        printf("%d/%d\n", 1 + c, a - c);
    else
        printf("%d/%d\n", a - c, 1 + c);
    return 0;
}