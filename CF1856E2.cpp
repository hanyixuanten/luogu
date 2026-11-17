#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> fri(n + 1);
    vector<int> fa(n + 1, 0);
    vector<int> cnt(n + 1, 1);
    vector<int> cmds;
    cmds.reserve(n);
    for (int i = 2, v; i <= n; ++i) {
        scanf("%d", &v);
        fri[i].push_back(v);
        fri[v].push_back(i);
    }
    vector<int> stk = {1};
    fa[1] = -1;
    while (!stk.empty()) {
        int now = stk.back();
        stk.pop_back();
        cmds.push_back(now);
        for (int i : fri[now]) {
            if (i == fa[now]) continue;
            fa[i] = now;
            stk.push_back(i);
        }
    }
    long long anss = 0;
    for (int p = (int)cmds.size() - 1; p >= 0; --p) {
        int now = cmds[p];
        map<int, int> cou;
        for (int i : fri[now]) {
            if (i == fa[now]) continue;
            cnt[now] += cnt[i];
            ++cou[cnt[i]];
        }
        bool flag = 0;
        for (int i : fri[now]) {
            if (i == fa[now]) continue;
            if(cnt[i] > (cnt[now] - 1) / 2) {
                anss += 1ll * (cnt[now] - 1 - cnt[i]) * cnt[i];
                flag = 1;
            }
        }
        if(flag) continue;
        int limm = cnt[now];
        vector<uint64_t> st((limm + 63) / 64, 0);
        st[0] = 1;
        for (auto [stree, count] : cou) {
            for (int k = 0; count > 0; ++k) {
                int bks = min(1 << k, count);
                count -= bks;
                int wd = (stree * bks) / 64;
                int bt = (stree * bks) % 64;
                for (int dst = (int)st.size() - 1; dst >= wd; --dst) {
                    int src = dst - wd;
                    uint64_t moved = st[src] << bt;
                    if (bt && src > 0) {
                        moved |= st[src - 1] >> (64 - bt);
                    }
                    st[dst] |= moved;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i < cnt[now]; ++i) {
            if ((st[i / 64] >> (i % 64)) & 1ull) {
                ans = max(ans, 1ll * (cnt[now] - 1 - i) * i);
            }
        }
        anss += ans;
    }
    printf("%lld\n", anss);
    return 0;
}
