// 90
#include <iostream>
using namespace std;
long long a, b, p;
void put(__int128 a)
{
    char c[60];
    if (a == 0)
        puts("0");
    int tot = 0;
    while (a > 0)
    {
        c[tot++] = a % 10 + '0';
        a /= 10;
    }
    for (int i = tot - 1; i >= 0; --i)
    {
        putchar(c[i]);
    }
    puts("");
}
int main()
{
    cin >> a >> b >> p;
    __int128 ans = ((__int128)a % p) * (b % p) % p;
    put(ans);
    return 0;
}