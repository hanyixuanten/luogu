#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int l, r, index;
    const bool operator<(const node &b) const
    {
        return r > b.r;
    }
} cow[50005];
bool used[50005];
int be[50005];

int main()
{
    scanf("%d", &n);
    int maxR = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &cow[i].l, &cow[i].r), cow[i].index = i, maxR = max(maxR, cow[i].r);
    sort(cow + 1, cow + n + 1, [](const node &a, const node &b)
         { return a.l < b.l; });
    int tot = 1, nx = 1;
    priority_queue<node> q;
    for (int t = 1; t <= maxR; t++)
    {
        while (!q.empty() && q.top().r < t)
            used[be[q.top().index]] = 0,q.pop();
        while (tot <= n && cow[tot].l <= t)
        {
            int stall = -1;
            for (int j = 1; j < nx; j++)
                if (!used[j])
                {
                    stall = j;
                    break;
                }
            if (stall == -1)
                stall = nx++;
            used[stall] = 1;
            be[cow[tot].index] = stall;
            q.push(cow[tot]);
            tot++;
        }
    }
    printf("%d\n", nx - 1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", be[i]);
    return 0;
}