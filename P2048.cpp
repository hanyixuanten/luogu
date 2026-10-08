#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int LOG = 20;
int n, k, L, R;
long long pre[MAXN];
int lg2[MAXN];
int st[LOG][MAXN];
int query(int l, int r) {
    int len = r - l + 1;
    int t = lg2[len];
    int x = st[t][l];
    int y = st[t][r - (1 << t) + 1];
    return pre[x] <= pre[y] ? x : y;
}
struct Node {
    long long val;
    int r, ql, qr, pos;
    bool operator<(const Node &other) const { return val < other.val; }
};
int main() {
    scanf("%d %d %d %d", &n, &k, &L, &R);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        pre[i] = pre[i - 1] + x;
    }
    int m = n + 1;
    lg2[1] = 0;
    for (int i = 2; i <= m; ++i) {
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int i = 0; i < m; ++i) {
        st[0][i] = i;
    }
    for (int j = 1; (1 << j) <= m; ++j) {
        for (int i = 0; i + (1 << j) <= m; ++i) {
            int x = st[j - 1][i];
            int y = st[j - 1][i + (1 << (j - 1))];
            st[j][i] = (pre[x] <= pre[y] ? x : y);
        }
    }
    priority_queue<Node> pq;
    for (int r = 1; r <= n; ++r) {
        int ql = max(0, r - R);
        int qr = r - L;
        if (ql <= qr) {
            int pos = query(ql, qr);
            pq.push({pre[r] - pre[pos], r, ql, qr, pos});
        }
    }
    long long ans = 0;
    for (int cnt = 0; cnt < k && !pq.empty(); ++cnt) {
        Node cur = pq.top();
        pq.pop();
        ans += cur.val;
        int r = cur.r;
        int ql = cur.ql;
        int qr = cur.qr;
        int pos = cur.pos;
        if (ql <= pos - 1) {
            int np = query(ql, pos - 1);
            pq.push({pre[r] - pre[np], r, ql, pos - 1, np});
        }
        if (pos + 1 <= qr) {
            int np = query(pos + 1, qr);
            pq.push({pre[r] - pre[np], r, pos + 1, qr, np});
        }
    }
    printf("%lld\n", ans);
    return 0;
}