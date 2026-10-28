# AT_arc073_b [ABC060D] Simple Knapsack 题解

注意到 $W$ 的值很大，若是直接计算会 TLE/MLE/RE。

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n; // 100
int w; // 1e9
pair<int, int> obj[105];
unordered_map<int, int> f[105];
int sumw[105];
int main()
{
    freopen("satchel.in", "r", stdin);
    freopen("satchel.out", "w", stdout);
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &obj[i].first, &obj[i].second);
    }
    sort(obj + 1, obj + n + 1, [](pii x, pii y)
         { return x.first > y.first; });
    for (int i = 1; i <= n; ++i)
        sumw[i] = sumw[i - 1] + obj[i].first;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = obj[i].first; j <= min(w, sumw[i]); ++j)
        {
            f[i][j] = max(f[i - 1][min(j, sumw[i - 1])], f[i - 1][j - obj[i].first] + obj[i].second);
        }
    }
    printf("%d\n", f[n][min(w, sumw[n])]);
    return 0;
}
```

令 $base = w_1, d_i = w_i - base$。由题，$0 \le d_i \le 3$。若选择 $k$ 个物品，总重量为 $\sum d_i + k \times base$，其中 $0 \le \sum d_i \le 300$。

考虑用 $f_{i, j}$ 记录选择 $i$ 个物品，$\sum d_i = j$ 的最大价值。对于每个物品：

$$f_{i + 1, j + d_i} = \max(f_{i, j} + v_i)$$

最后枚举 $i, j$，若 $i \times base + j \le W$ 则更新答案。

[code](../AT_arc073_b.cpp)
