// 128
#include <bits/stdc++.h>
using namespace std;
int q;
int qjh[1000005];
int ans[1000005];
vector<int> s, tmp;
int main()
{
    cin >> q;
    for (int i = 0; i <= q + 1; ++i)
        ans[i] = INT_MIN;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'I')
        {
            int x;
            cin >> x;
            s.push_back(x);
            qjh[s.size()] = qjh[s.size() - 1] + x;
            ans[s.size()] = max(ans[s.size() - 1], qjh[s.size()]);
        }
        else if (c == 'D')
        {
            if (!s.empty())
                s.pop_back();
        }
        else if (c == 'L')
        {
            if (!s.empty())
            {
                tmp.push_back(s[s.size() - 1]);
                s.pop_back();
            }
        }
        else if (c == 'R')
        {
            if (!tmp.empty())
            {
                s.push_back(tmp[tmp.size() - 1]);
                qjh[s.size()] = qjh[s.size() - 1] + tmp[tmp.size() - 1];
                ans[s.size()] = max(ans[s.size() - 1], qjh[s.size()]);
                tmp.pop_back();
            }
        }
        else
        {
            int x;
            cin >> x;
            cout << ans[x] << endl;
        }
    }
    return 0;
}