#include <bits/stdc++.h>
int n, m;
int a[500005];
int t[500005];
using namespace std;
struct seg {
    int l, r;
    long long num, lz;
} seg[2000005];
void pd(int now) {
    seg[now * 2].lz += seg[now].lz, seg[now * 2 + 1].lz += seg[now].lz;
    seg[now * 2].num += seg[now].lz, seg[now * 2 + 1].num += seg[now].lz;
    seg[now].lz = 0;
}
void pu(int now) { seg[now].num = max(seg[now * 2].num, seg[now * 2 + 1].num); }
void init(int now, int l, int r) {
    seg[now].l = l, seg[now].r = r;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    init(now * 2, l, mid);
    init(now * 2 + 1, mid + 1, r);
}
long long query(int now, int l, int r) {
    if (r < seg[now].l || l > seg[now].r) {
        return -1e18;
    }
    if (r >= seg[now].r && l <= seg[now].l) {
        return seg[now].num;
    }
    pd(now);
    return max(query(now * 2, l, r), query(now * 2 + 1, l, r));
}
void edit(int now, int l, int r, long long num) {
    if (r < seg[now].l || l > seg[now].r) {
        return;
    }
    if (r >= seg[now].r && l <= seg[now].l) {
        seg[now].num += num, seg[now].lz += num;
        return;
    }
    pd(now);
    edit(now * 2, l, r, num);
    edit(now * 2 + 1, l, r, num);
    pu(now);
}
int pre[500005];
int main() {
    scanf("%d%d", &n, &m);
    init(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (pre[a[i]])
            edit(1, pre[a[i]], i - 1, t[a[i]]);
        pre[a[i]] = i;
        if (i > 1)
            edit(1, i, i, max(query(1, 1, i - 1), 0ll));
    }
    printf("%lld\n", query(1, 1, n));
    return 0;
}
