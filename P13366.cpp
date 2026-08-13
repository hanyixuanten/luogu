#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, m;
string d[10005], l[105];
int pattern(int now, char let) // 转化为二进制保存
{
    int res = 0;
    for (int i = 0; i < d[now].length(); ++i)
        if (d[now][i] == let)
            res |= 1 << i; // 这一位设为1
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int task = 1; task <= t; ++task)
    {
        cin >> n >> m;
        vector<int> bl[11]; // 按照单词长度分类，保存标号
        for (int i = 1; i <= n; ++i)
        {
            cin >> d[i];
            bl[d[i].length()].push_back(i);
        }
        for (int i = 1; i <= m; ++i)
            cin >> l[i];
        cout << "Case #" << task << ":";
        for (int li = 1; li <= m; ++li)
        {
            vector<int> cnt(n + 1, 0);
            vector<vector<int>> groups; // 保存各个步骤分组情况
            for (int length = 1; length <= 10; ++length)
                if (!bl[length].empty())
                    groups.push_back(bl[length]);
            for (char let : l[li])
            {
                vector<vector<int>> newgroups;
                for (const vector<int> &group : groups)
                {
                    if (group.size() == 1)
                        continue;
                    map<int, vector<int>> sgroups;
                    bool flag = 0;
                    for (int wi : group)
                    {
                        int pat = pattern(wi, let);
                        if (pat != 0)
                            flag = 1;
                        sgroups[pat].push_back(wi);
                    }
                    if (!flag)
                    {
                        newgroups.push_back(group);
                        continue;
                    }
                    for (int wi : sgroups[0])
                        ++cnt[wi];
                    for (auto k : sgroups)
                        newgroups.push_back(k.second);
                }
                groups.swap(newgroups);
            }
            int ansi = 1;
            for (int wi = 2; wi <= n; ++wi)
                if (cnt[wi] > cnt[ansi])
                    ansi = wi;
            cout << ' ' << d[ansi];
        }
        cout << '\n';
    }
    return 0;
}