#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a = max(abs(a), abs(b));
    c = max(abs(c), abs(d));
    if ((long long)((int)a * (int)c) != (long long)a * (long long)c)
    {
        puts("long long int");
    }
    else
    {
        puts("int");
    }
    return 0;
}