#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("repetitions.in", "r", stdin);
    // freopen("repetitions.out", "w", stdout);
    string s1, s2;
    long long n1, n2;
    while (cin >> s2 >> n2 >> s1 >> n1)
    {
        int len1 = s1.size(), len2 = s2.size();
        // 预处理：对 s2 的每个起始位置 j，扫描一遍 s1 后得到：
        // nxt[j] = 结束时在 s2 中的位置
        // cnt[j] = 期间完整匹配了多少个 s2
        vector<int> nxt(len2);
        vector<long long> cnt(len2, 0);
        for (int j = 0; j < len2; j++)
        {
            int pos = j;
            for (int i = 0; i < len1; i++)
            {
                if (s1[i] == s2[pos])
                {
                    pos++;
                    if (pos == len2)
                    {
                        cnt[j]++;
                        pos = 0;
                    }
                }
            }
            nxt[j] = pos;
        }
        // 模拟 n1 轮，每轮用预处理结果 O(1) 转移
        long long total = 0;
        int cur = 0;
        for (long long i = 0; i < n1; i++)
        {
            total += cnt[cur];
            cur = nxt[cur];
        }
        cout << total / n2 << endl;
    }
    return 0;
}
