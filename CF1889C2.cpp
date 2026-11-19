#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> dp;
int n, m, k;
pair<int, int> p[200005];
const int C = 100000000;
int t;
void calc(int x, int y, int z, int t)
{
    int w = (x << 22) | (y << 18) | z;
    dp[w] = min(dp[w], t - C);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < m; ++i)
            cin >> p[i].first >> p[i].second;
        if (k >= m)
        {
            cout << n << "\n";
            continue;
        }
        sort(p, p + m), dp.clear();
        set<int> st;
        st.insert(0);
        int ans = n + 1;
        calc(0, 0, 0, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int l : st)
                for (int j = 0; j <= min(k, i); ++j)
                    if (dp.count((i << 22) | (j << 18) | l))
                    {
                        int t = dp[(i << 22) | (j << 18) | l] + C;
                        dp.erase((i << 22) | (j << 18) | l);
                        calc(i + 1, j, max(l, p[i].second), t + max(p[i].second, l) - max(p[i].first - 1, l));
                        if (j < k)
                            calc(i + 1, j + 1, l, t);
                    }
            st.insert(p[i].second);
            while ((int)st.size() > k + 1)
                st.erase(st.begin());
        }
        for (int l : st)
            for (int j = 0; j <= k; j++)
                ans = min(ans, dp[(m << 22) | (j << 18) | l] + C);
        cout << n - ans << "\n";
    }
    return 0;
}