// 124
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int to_num(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    else
        return c - 'a' + 36;
}
char to_char(int i)
{
    if (0 <= i && i <= 9)
        return i + '0';
    else if (10 <= i && i <= 35)
        return i - 10 + 'A';
    else
        return i - 36 + 'a';
}
void conv(int inbase, int outbase, string s)
{
    vector<int> n(s.size(), 0), r;
    for (int i = 0; i < s.size(); ++i)
        n[i] = to_num(s[i]);
    while (n.size())
    {
        vector<int> e(n.size(), 0);
        int yy = 0;
        for (int i = 0; i < n.size(); ++i)
        {
            int c = n[i] + yy * inbase;
            e[i] = c / outbase, yy = c % outbase;
        }
        n = e;
        r.push_back(yy);
        while (!n.empty() && n[0] == 0)
            n.erase(n.begin());
    }
    reverse(r.begin(), r.end());
    printf("%d ", inbase);
    cout << s << '\n';
    printf("%d ", outbase);
    for (int i : r)
        putchar(to_char(i));
    puts("\n");
}
signed main()
{
    scanf("%lld", &t);
    while (t--)
    {
        int in, out;
        scanf("%lld%lld", &in, &out);
        string inn;
        cin >> inn;
        conv(in, out, inn);
    }
    return 0;
}