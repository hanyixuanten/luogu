// 117
#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
char a[20][10];
int cnt = 1, ans;
bool vis[20][10];
int trans(char tmp)
{
    switch (tmp)
    {
    case 'A':
        return 1;
    case '0':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    }
    return tmp - '0';
}
int main()
{
    for (int i = 1; i <= 13; i++)
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    while (cnt <= 4)
    {
        char tmp = a[13][cnt++];
        while (tmp != 'K')
        {
            int t = trans(tmp);
            for (int i = 4; i >= 1; i--)
            {
                if (!vis[t][i])
                {
                    vis[t][i] = true, m[tmp]++;
                    if (m[tmp] == 4 && tmp != 'K')
                        ans++;
                    tmp = a[t][i];
                    break;
                }
            }
            t = trans(tmp);
        }
    }
    cout << ans;
    return 0;
}