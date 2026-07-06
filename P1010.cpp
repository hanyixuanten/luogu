#include <bits/stdc++.h>
using namespace std;
string fn(int q)
{
    if (q == 3)
        return "2+2(0)";
    if (q == 2)
        return "2";
    if (q == 1)
        return "2(0)";
    int l = (int)log2(q);
    string t1 = "2(", t2 = ")", t3 = ")+";
    if (q == (1 << l))
        return t1 + fn(l) + t2;
    else
        return t1 + fn(l) + t3 + fn(q - (1 << l));
}
int main()
{
    int n;
    scanf("%d", &n);
    cout << fn(n) << endl;
    return 0;
}