#include <bits/stdc++.h>
using namespace std;

int c, n;
pair<int, int> cc[505];
int tmpx[505], tmpy[505];
int sum[505][505];
int totx, toty;
bool check(int len)
{
    for (int i = 1; i <= totx; ++i)
    {
        int j = i;
        while (j <= totx && tmpx[j] - tmpx[i] <= len - 1)
            j++;
        j--;
        int l = 1;
        for (int k = 1; k <= toty; ++k)
        {
            if (l < k)
                l = k;
            while (l <= toty && tmpy[l] - tmpy[k] <= len - 1)
                l++;
            l--;
            if (l >= k)
            {
                int cnt = sum[j][l] - sum[i - 1][l] - sum[j][k - 1] + sum[i - 1][k - 1];
                if (cnt >= c)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d", &c, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &cc[i].first, &cc[i].second);
        tmpx[i] = cc[i].first, tmpy[i] = cc[i].second;
    }
    sort(tmpx + 1, tmpx + n + 1);
    totx = unique(tmpx + 1, tmpx + n + 1) - (tmpx + 1);
    sort(tmpy + 1, tmpy + n + 1);
    toty = unique(tmpy + 1, tmpy + n + 1) - (tmpy + 1);
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i)
    {
        int x = lower_bound(tmpx + 1, tmpx + totx + 1, cc[i].first) - tmpx;
        int y = lower_bound(tmpy + 1, tmpy + toty + 1, cc[i].second) - tmpy;
        sum[x][y]++;
    }
    for (int i = 1; i <= totx; ++i)
    {
        for (int j = 1; j <= toty; ++j)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int L = 1, R = max(tmpx[totx] - tmpx[1] + 1, tmpy[toty] - tmpy[1] + 1), ans;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (check(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }

    printf("%d\n", ans);
    return 0;
}