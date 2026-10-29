#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> fri[100005];
int p[100005];
int dfn[100005];
int cnt[100005];
int nowdfn;
struct SEG{
    int num[400005], lt[400005];
    void pd(int now, int nl, int nr) {
        int nmid = (nl + nr) >> 1;
        num[now * 2] += lt[now] * (nmid - nl + 1);
        num[now * 2 + 1] += lt[now] * (nr - nmid);
        lt[now * 2] += lt[now];
        lt[now * 2 + 1] += lt[now];
        lt[now] = 0;
    }
    void pu(int now) {num[now] = num[now * 2] + num[now * 2 + 1];}
    void add(int now, int nl, int nr, int l, int r, int nn) {
        if(nl > r || nr < l) return;
        if(l <= nl && nr <= r) {
            num[now] += nn * (nr - nl + 1);
            lt[now] += nn;
            return;
        }
        int nmid = (nl + nr) >> 1;
        add(now * 2, nl, nmid, l, r, nn);
        add(now * 2 + 1, nmid + 1, nr, l, r, nn);
        pu(now);
    }
    int query(int now, int nl, int nr, int l, int r) {
        if(nl > r || nr < l) return 0;
        if(l <= nl && nr <= r) return num[now];
        int nmid = (nl + nr) >> 1;
        pd(now, nl, nr);
        return query(now * 2, nl, nmid, l, r) + query(now * 2 + 1, nmid + 1, nr, l, r);
    }
}seg;
void dfs(int now, int from) {
    cnt[now] = 1;
    dfn[now] = ++nowdfn;
    for(int i : fri[now]) {
        if(i == from) continue;
        dfs(i, now);
        cnt[now] += cnt[i];
    }
}
signed main() {
    scanf("%lld", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%lld%lld", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &p[i]);
        printf("%lld\n", seg.query(1, 1, n, dfn[p[i]], dfn[p[i]]));
        seg.add(1, 1, n, dfn[p[i]], dfn[p[i]] + cnt[p[i]] - 1, 1);
    }
    return 0;
}