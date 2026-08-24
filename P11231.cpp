#include <bits/stdc++.h>
using namespace std;
int n;
int a;
map<int, int> cou;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        cou[a]++;
    }
    int maxx = 0;
    for (auto k : cou)
        maxx = max(maxx, k.second);
    printf("%d\n", maxx);
    return 0;
}