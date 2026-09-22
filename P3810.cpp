#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct Node {
    int a, b, c;
    int cnt = 1; // 相同三元组的个数
    int id = 0;  // 在去重数组中的编号
    bool operator<(const Node &o) const {
        if (a != o.a)
            return a < o.a;
        if (b != o.b)
            return b < o.b;
        return c < o.c;
    }
} e[maxn], tmp[maxn];
int n, k, m;
int ans[maxn]; // ans[i]: 去重后第 i 个元素的答案
int res[maxn]; // res[d]: 答案恰为 d 的元素个数
struct BIT {
    int tree[200005];
    int lowbit(int x) { return x & -x; }
    void add(int x, int v) {
        for (; x <= k; x += lowbit(x))
            tree[x] += v;
    }
    int sum(int x) {
        int r = 0;
        for (; x > 0; x -= lowbit(x))
            r += tree[x];
        return r;
    }
} bit;
void cdq(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    // 左半 -> 右半 的贡献：b 用双指针，c 用树状数组
    int i = l, j = mid + 1;
    while (j <= r) {
        while (i <= mid && e[i].b <= e[j].b) {
            bit.add(e[i].c, e[i].cnt);
            ++i;
        }
        ans[e[j].id] += bit.sum(e[j].c);
        ++j;
    }
    // 撤销树状数组（不能 memset，太慢，要按插入的反操作回滚）
    for (int t = l; t < i; ++t)
        bit.add(e[t].c, -e[t].cnt);
    // 归并：让 e[l..r] 按 b 有序，供上一层双指针使用
    i = l;
    j = mid + 1;
    int t = l;
    while (i <= mid && j <= r)
        tmp[t++] = (e[i].b <= e[j].b) ? e[i++] : e[j++];
    while (i <= mid)
        tmp[t++] = e[i++];
    while (j <= r)
        tmp[t++] = e[j++];
    for (t = l; t <= r; ++t)
        e[t] = tmp[t];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
    sort(e + 1, e + n + 1);
    // 去重
    m = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && e[i].a == e[m].a && e[i].b == e[m].b && e[i].c == e[m].c) {
            ++e[m].cnt;
        } else {
            e[++m] = e[i];
            e[m].cnt = 1;
        }
    }
    for (int i = 1; i <= m; ++i)
        e[i].id = i;
    cdq(1, m);
    for (int i = 1; i <= m; ++i) {
        ans[e[i].id] += e[i].cnt - 1; // 与自己完全相同的同族元素
        res[ans[e[i].id]] += e[i].cnt;
    }
    for (int d = 0; d < n; ++d)
        printf("%d\n", res[d]);
    return 0;
}