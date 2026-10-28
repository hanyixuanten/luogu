#include<bits/stdc++.h>
using namespace std;
struct node {
    long long sum;
    long long lt1;
    long long lt2 = 1;
} seg[400005];
int n, q;
long long m;
int a[100005];
void pu(int now) {
    seg[now].sum = (seg[now * 2].sum + seg[now * 2 + 1].sum) % m;
}
void apply(int now, int len, long long mul, long long add) {
    seg[now].sum = (seg[now].sum * mul % m + add * len % m) % m;
    seg[now].lt2 = seg[now].lt2 * mul % m;
    seg[now].lt1 = (seg[now].lt1 * mul % m + add) % m;
}
void pd(int now, int nl, int nr) {
    if (seg[now].lt1 == 0 && seg[now].lt2 == 1) return;
    int mid = (nl + nr) >> 1;
    apply(now * 2, mid - nl + 1, seg[now].lt2, seg[now].lt1);
    apply(now * 2 + 1, nr - mid, seg[now].lt2, seg[now].lt1);
    seg[now].lt1 = 0;
    seg[now].lt2 = 1;
}

void init(int now, int nl, int nr) {
    if (nl == nr) {
        seg[now].sum = a[nl] % m;
        return;
    }
    int mid = (nl + nr) >> 1;
    init(now * 2, nl, mid);
    init(now * 2 + 1, mid + 1, nr);
    pu(now);
}
void add(int now, int nl, int nr, int l, int r, long long nn) {
    if (nl > r || nr < l) return;
    if (l <= nl && nr <= r) {
        apply(now, nr - nl + 1, 1, nn % m);
        return;
    }
    int mid = (nl + nr) >> 1;
    pd(now, nl, nr);
    add(now * 2, nl, mid, l, r, nn);
    add(now * 2 + 1, mid + 1, nr, l, r, nn);
    pu(now);
}
void mul(int now, int nl, int nr, int l, int r, long long nn) {
    if (nl > r || nr < l) return;
    if (l <= nl && nr <= r) {
        apply(now, nr - nl + 1, nn % m, 0);
        return;
    }
    int mid = (nl + nr) >> 1;
    pd(now, nl, nr);
    mul(now * 2, nl, mid, l, r, nn);
    mul(now * 2 + 1, mid + 1, nr, l, r, nn);
    pu(now);
}
long long query(int now, int nl, int nr, int l, int r) {
    if (nl > r || nr < l) return 0;
    if (l <= nl && nr <= r) {
        return seg[now].sum % m;
    }
    int mid = (nl + nr) >> 1;
    pd(now, nl, nr);
    return (query(now * 2, nl, mid, l, r) + query(now * 2 + 1, mid + 1, nr, l, r)) % m;
}
int main() {
    scanf("%d%d%lld", &n, &q, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    init(1, 1, n);
    while (q--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            long long k;
            scanf("%lld", &k);
            mul(1, 1, n, x, y, k);
        } else if (op == 2) {
            long long k;
            scanf("%lld", &k);
            add(1, 1, n, x, y, k);
        } else {
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }

    return 0;
}