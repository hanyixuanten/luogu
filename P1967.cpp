#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[10005];
vector<pair<int, pair<int, int>>> edge;
vector<pair<int, int>> fri[10005];
struct BCJ {
    int fa[10005];
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
} b;
struct SEG {
    int num[10005 * 4];
    void init(int now, int nl, int nr) {
        if (nl == nr) {
            num[now] = a[nl];
            return;
        }
        int mid = (nl + nr) >> 1;
        init(now * 2, nl, mid);
        init(now * 2 + 1, mid + 1, nr);
        num[now] = min(num[now * 2], num[now * 2 + 1]);
    }
    int query(int now, int nl, int nr, int l, int r) {
        if (nr < l || nl > r) return INT_MAX;
        if (l <= nl && nr <= r) return num[now];
        int mid = (nl + nr) >> 1;
        return min(query(now * 2, nl, mid, l, r), query(now * 2 + 1, mid + 1, nr, l, r));
    }
} seg;
int fa[10005];
pair<int, int> son[10005];
int cnt[10005];
int top[10005];
int dfn[10005];
int dep[10005];
int nowdfn;
void dfs1(int now, int from) {
    cnt[now] = 1;
    for (auto i : fri[now]) {
        int v = i.second;
        int w = i.first;
        if (v == from) continue;
        fa[v] = now;
        dep[v] = dep[now] + 1;
        dfs1(v, now);
        cnt[now] += cnt[v];
        if (cnt[son[now].first] < cnt[v]) {
            son[now].first = v;
            son[now].second = w;
        }
    }
}
void dfs2(int now, int from, int w) {
    dfn[now] = ++nowdfn;
    top[now] = from;
    a[dfn[now]] = w;
    if (son[now].first) {
        dfs2(son[now].first, from, son[now].second);
    }
    for (auto i : fri[now]) {
        int v = i.second;
        int ww = i.first;
        if (v == fa[now] || v == son[now].first) continue;
        dfs2(v, v, ww);
    }
}
int pt(int x, int y) {
    if (x == y) return INT_MAX;
    int ans = INT_MAX;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = min(ans, seg.query(1, 1, n, dfn[top[x]], dfn[x]));
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    if (dfn[y] + 1 <= dfn[x]) {
        ans = min(ans, seg.query(1, 1, n, dfn[y] + 1, dfn[x]));
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        b.fa[i] = i;
    }
    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end(),
         [](const pair<int, pair<int, int>> &x,
            const pair<int, pair<int, int>> &y) {
             return x.first > y.first;
         });
    for (auto i : edge) {
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if (b.find(u) != b.find(v)) {
            fri[u].push_back({w, v});
            fri[v].push_back({w, u});
            b.fa[b.find(u)] = b.find(v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            dfs1(i, 0);
            dfs2(i, i, INT_MAX);
        }
    }
    seg.init(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (b.find(x) != b.find(y)) {
            printf("-1\n");
            continue;
        }
        int ans = pt(x, y);
        printf("%d\n", ans == INT_MAX ? -1 : ans);
    }

    return 0;
}