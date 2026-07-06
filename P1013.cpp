#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int n;
char c[12];         // 表示存在的字母，0位置为+，从1开始为字母
map<char, int> num; // 表示字母所对的位置
int ans[12];        // 表示答案，与c匹配从1开始
string a[12][12];   // 储存整个输入
bool tried[12];     // 表示这个数有没有用过
bool dfs(int now)
{
    if (now == n)
    {
        // 检测
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                int x1 = ans[num[a[0][j][0]]], x2 = ans[num[a[i][0][0]]]; // 第一个数和第二个数
                int x12 = 0;                                              // 表格中的和在十进制下的表达
                for (int k = 0; k < a[i][j].size(); k++)
                {
                    x12 *= n - 1;
                    x12 += ans[num[a[i][j][k]]];
                }
                if (x1 + x2 != x12)
                    return 0;
            }
        }
        return 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (!tried[i])
        {
            tried[i] = 1;
            ans[now] = i;
            if (dfs(now + 1))
                return 1;
            tried[i] = 0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            if (i == 0)
                c[j] = a[i][j][0], num[a[i][j][0]] = j;
        }
    if (dfs(1))
    {
        for (int i = 1; i < n; ++i)
        {
            printf("%c=%d ", c[i], ans[i]);
        }
        printf("\n%d\n", n - 1);
    }
    else
        printf("ERROR!\n");
    return 0;
}