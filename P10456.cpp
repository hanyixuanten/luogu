// 116
#include <bits/stdc++.h>
using namespace std;
bool dddd[5][5];
bool hang[5];
bool lie[5];
bool chosen[5][5];
vector<pair<int, int>> cc, anss;
void in()
{
    for (int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 4; ++j)
            dddd[i][j] = (s[j] == '+');
    }
}
void dfs(int x, int y)
{
    if (x == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (hang[i] ^ lie[j] ^ dddd[i][j] ^ chosen[i][j])
                    return;
            }
        }
        if (anss.empty() || (int)cc.size() < anss.size())
        {
            anss = cc;
        }
        return;
    }
    hang[x] = !hang[x], lie[y] = !lie[y], chosen[x][y] = 1;
    cc.push_back({x, y});
    dfs((y == 3) ? x + 1 : x, (y == 3) ? 0 : y + 1);
    hang[x] = !hang[x], lie[y] = !lie[y], chosen[x][y] = 0;
    cc.pop_back();
    dfs((y == 3) ? x + 1 : x, (y == 3) ? 0 : y + 1);
}
int main()
{
    in();
    dfs(0, 0);
    printf("%d\n", anss.size());
    for (int i = 0; i < (int)anss.size(); ++i)
    {
        printf("%d %d\n", anss[i].first + 1, anss[i].second + 1);
    }
}