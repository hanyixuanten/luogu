// 93
#include <cstdio>
using namespace std;
bool ch[50];
int n, m;
void dfs(int count, int now)
{
    if (now > n)
    {
        if (count != m)
            return;
        for (int i = 1; i <= n; ++i)
        {
            if (ch[i])
                printf("%d ", i);
        }
        puts("");
        return;
    }
    ch[now] = 1;
    dfs(count + 1, now + 1);
    ch[now] = 0;
    dfs(count, now + 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    dfs(0, 1);
    return 0;
}