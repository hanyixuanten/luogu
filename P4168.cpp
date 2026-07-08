#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40005;
const int MAX2 = 205;

int n, q;
int a[MAXN], comp[MAXN], vals[MAXN], vcnt, l0;
int pcnt[MAX2][MAXN]; // 前缀计数 pcnt[i][v] = 块[0..i]中压缩值v的出现次数
int bval[MAX2][MAX2]; // 块区间[i,j]的众数值
int bcnt[MAX2][MAX2]; // 块区间[i,j]的众数出现次数

void lsh() // 离散化
{
    for (int i = 0; i < n; i++)
        vals[i] = a[i];
    sort(vals, vals + n);
    vcnt = unique(vals, vals + n) - vals;
    for (int i = 0; i < n; i++)
        comp[i] = lower_bound(vals, vals + vcnt, a[i]) - vals;
}

void bkcnt()
{
    int totalBlocks = n / l0;
    memset(pcnt, 0, sizeof(pcnt));
    for (int i = 0; i <= totalBlocks; i++)
    {
        if (i > 0)
            memcpy(pcnt[i], pcnt[i - 1], sizeof(int) * vcnt);
        for (int j = i * l0; j < (i + 1) * l0 && j < n; j++)
            pcnt[i][comp[j]]++;
    }
}

void pre() // O(n sqrt(n))
{
    static int freq[MAXN];
    int totalBlocks = n / l0;
    for (int i = 0; i <= totalBlocks; ++i)
    {
        int maxc = 0, maxp = 0;
        for (int j = i; j <= totalBlocks; ++j)
        {
            for (int k = j * l0; k < (j + 1) * l0 && k < n; ++k)
            {
                freq[comp[k]]++;
                int f = freq[comp[k]];
                if (f > maxc || (f == maxc && a[k] < a[maxp]))
                    maxc = f, maxp = k;
            }
            bval[i][j] = a[maxp];
            bcnt[i][j] = maxc;
        }
        memset(freq, 0, sizeof(int) * vcnt);
    }
}

int query(int l, int r) // 返回众数 O(sqrt(n))
{
    static int freq[MAXN];
    static int sideVals[MAXN];
    int sideN;

    if (l / l0 == r / l0) // 在同一个区块内
    {
        int maxc = 0, maxp = l;
        for (int i = l; i <= r; ++i)
        {
            freq[comp[i]]++;
            int f = freq[comp[i]];
            if (f > maxc || (f == maxc && a[i] < a[maxp]))
                maxc = f, maxp = i;
        }
        int result = a[maxp];
        for (int i = l; i <= r; ++i)
            freq[comp[i]] = 0;
        return result;
    }
    int bl = l / l0, br = r / l0;
    // 中间完整块 [bl+1, br-1] 的众数
    int best_val = 0, best_cnt = 0;
    if (bl + 1 <= br - 1)
    {
        best_val = bval[bl + 1][br - 1];
        best_cnt = bcnt[bl + 1][br - 1];
    }
    // 两侧零散部分 — 用数组O(1)计数
    sideN = 0;
    for (int i = l; i <= (bl + 1) * l0 - 1; ++i)
    {
        int cv = comp[i];
        freq[cv]++;
        if (freq[cv] == 1)
            sideVals[sideN++] = cv;
    }
    for (int i = br * l0; i <= r; ++i)
    {
        int cv = comp[i];
        freq[cv]++;
        if (freq[cv] == 1)
            sideVals[sideN++] = cv;
    }
    for (int j = 0; j < sideN; ++j)
    {
        int cv = sideVals[j];
        int mid = 0;
        if (bl + 1 <= br - 1)
            mid = pcnt[br - 1][cv] - pcnt[bl][cv];
        int total = freq[cv] + mid;
        int ov = vals[cv];
        if (best_cnt == 0 || total > best_cnt || (total == best_cnt && ov < best_val))
            best_cnt = total, best_val = ov;
    }
    // 清理
    for (int j = 0; j < sideN; ++j)
        freq[sideVals[j]] = 0;
    return best_val;
}

int main()
{
    // freopen("dandelion.in", "r", stdin);
    // freopen("dandelion.out", "w", stdout);
    scanf("%d%d", &n, &q);
    l0 = (int)sqrt(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    lsh();
    bkcnt();
    pre();
    int ans = 0;
    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l = ((l + ans - 1) % n) + 1, r = ((r + ans - 1) % n) + 1; // 加密强制在线算法
        if (l > r)
            swap(l, r);
        ans = query(l - 1, r - 1);
        printf("%d\n", ans);
    }
    return 0;
}