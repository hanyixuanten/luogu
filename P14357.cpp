#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool m(int a, int b)
{
    return a > b;
}
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            cnt++;
            a[cnt] = s[i] - '0';
        }
    }
    sort(a + 1, a + cnt + 1, m);
    for (int i = 1; i <= cnt; i++)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}