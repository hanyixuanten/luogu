// 94
#include <iostream>

using namespace std;

const int N = 20;
int n,k;
bool st[N];  // 数字是否用过
int path[N]; // 保存数列

void dfs(int cnt)
{
    if (cnt > k)
    {
        for (int i = 1; i <= k; i++)
            printf("%d ", path[i]);
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            path[cnt] = i, st[i] = 1;
            dfs(cnt + 1);
            path[cnt] = 0, st[i] = 0;
        }
    }
}

int main()
{
    scanf("%d%d", &n,&k);
    dfs(1);
    return 0;
}