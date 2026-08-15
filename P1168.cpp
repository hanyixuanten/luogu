// 106
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005], ord[100005], pos[100005];
int pre[100005], nxt[100005];
int ans[100005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), ord[i] = i;
    sort(ord + 1, ord + n + 1, [](int x, int y)
         { return a[x] != a[y] ? a[x] < a[y] : x < y; });
    for (int rank = 1; rank <= n; ++rank)
    {
        int x = ord[rank];
        pos[x] = rank, pre[x] = (rank == 1 ? 0 : ord[rank - 1]), nxt[x] = (rank == n ? 0 : ord[rank + 1]);
    }
    int mid = ord[n / 2 + 1], cnt = 0;
    for (int len = n; len >= 1; --len)
    {
        if (len & 1)
            ans[++cnt] = a[mid];
        if (len == 1)
            break;
        int x = len;
        if (len & 1)
        {
            if (pos[x] <= pos[mid])
                mid = nxt[mid];
        }
        else if (pos[x] >= pos[mid])
            mid = pre[mid];
        if (pre[x])
            nxt[pre[x]] = nxt[x];
        if (nxt[x])
            pre[nxt[x]] = pre[x];
    }
    for (int i = cnt; i >= 1; --i)
        printf("%d\n", ans[i]);
    return 0;
}
