#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, s, t;
int inf = 1e12;
string str;
signed main()
{
    cin >> n >> s;
    cin >> str;
    for (auto i : str)
    {
        if (i == 'U')
        {
            if (s == 1)
                continue;
            if (t)
            {
                t--;
                continue;
            }
            s /= 2;
        }
        if (i == 'L')
        {
            if (2 * s > inf)
                t++;
            else
                s *= 2;
        }
        else if (i == 'R')
        {
            if (2 * s + 1 > inf)
                t++;
            else
                s = s * 2 + 1;
        }
    }
    cout << s << endl;
    return 0;
}