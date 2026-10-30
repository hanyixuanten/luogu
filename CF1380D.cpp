#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long x, y;
int a[200005];
int b, preb;
int pos[200005];
bool k_is_better;
vector<int> mor;
long long del(int pre, int todo)
{
    if (todo <= pre)
        return -1;
    if (todo == pre + 1)
        return 0;
    mor.clear();
    for (int j = pre + 1; j <= todo - 1; ++j)
        if (a[j] > max(a[todo], a[pre]))
            mor.push_back(j);
    if (!mor.empty() && (todo - pre - 1) < k) // 如果有大数且长度不足以运行一次 k 则不存在
        return -1;
    if (k_is_better)
    {
        return ((todo - pre - 1) % k) * y + ((todo - pre - 1) / k) * x; // 先用 y 移除多余的数，最后用多个 k 直接删完
    }
    else
    {
        if (!mor.empty())
            return (todo - pre - 1 - k) * y + x; // 用一次k清除最大数，其余用y
        else
            return (todo - pre - 1) * y; // 全部用y
    }
    return 0;
}
int main()
{
    scanf("%d%d%lld%d%lld", &n, &m, &x, &k, &y);
    k_is_better = x < (k * y);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b);
        int todo = pos[b], pre = 0;
        if (i != 1)
            pre = pos[preb];
        long long d = del(pre, todo);
        if (d == -1ll)
        {
            printf("-1\n");
            return 0;
        }
        ans += d;
        preb = b;
    }
    long long d = del(pos[b], n + 1);
    if (d == -1ll)
    {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n", ans + d);
    return 0;
}
/*
若 k 删除更优，先删到能被 k 整除的长度，则先 k 删除，最后运行多次 k 删除
len % k
若 1 删除更优，先用 k 删除删去大于两边的，最后用 1 删除
7 2
3 3 1
5 7 0 3 1 6 4
5 4

输出 5
*/