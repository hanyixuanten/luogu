// 92
#include <cstdio>
using namespace std;
bool ch[20];
int n;
void dfs(int now)
{
    if (now > n)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (ch[i])
                printf("Y");
            else
                printf("N");
        }
        puts("");
        return;
    }
    ch[now]=0;
    dfs(now + 1);
    ch[now]=1;
    dfs(now + 1);
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}