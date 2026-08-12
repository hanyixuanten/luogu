#include <cstdio>
#include <stack>
using namespace std;
int n, q;
struct node
{
    int d, c;
} p[100005];
int nxt[100005][20];
long long sum[100005][20];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i].d, &p[i].c);
        sum[i][0] = p[i].c;
    }
    stack<pair<int, int>> s;
    nxt[n][0] = 0;
    s.push({p[n].d, n});
    for (int i = n - 1; i >= 1; --i)
    {
        while (!s.empty() && s.top().first <= p[i].d)
            s.pop();
        if (s.empty())
            nxt[i][0] = 0;
        else
            nxt[i][0] = s.top().second;
        s.push({p[i].d, i});
    }
    for (int k = 1; k <= 18; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
            sum[i][k] = sum[i][k - 1] + sum[nxt[i][k - 1]][k - 1];
        }
    }
    while (q--)
    {
        int r;
        long long v;
        scanf("%d%lld", &r, &v);
        for (int k = 18; k >= 0; --k)
        {
            if (sum[r][k] < v)
            {
                v -= sum[r][k];
                r = nxt[r][k];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}