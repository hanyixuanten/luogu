#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e18;
int n;
pair<pii, pii> doors[100005];
int m;
int dp[100005][20][2][2];
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i < n; ++i)
    {
        int xx1, yy1, xx2, yy2;
        scanf("%lld%lld%lld%lld", &xx1, &yy1, &xx2, &yy2);
        doors[i] = {{xx1, yy1}, {xx2, yy2}};
    }
    for(int i = 2; i < n; ++i) {
        for (int a = 0; a < 2; ++a) {
            pii out;
            if (a == 0) out = {doors[i - 1].first.first + 1, doors[i - 1].first.second};
            else out = {doors[i - 1].second.first, doors[i - 1].second.second + 1};
            for (int b = 0; b < 2; ++b) {
                pii dest = (b == 0) ? doors[i].first : doors[i].second;
                dp[i - 1][0][a][b] = 1 + abs(out.first - dest.first) + abs(out.second - dest.second);
            }
        }
    }
    for(int i = 1; i <= 19; ++i) {
        for(int j = 1; j + (1 << i) <= n - 1; ++j) {
            dp[j][i][0][0] = min(dp[j][i - 1][0][0] + dp[j + (1 << (i - 1))][i - 1][0][0], dp[j][i - 1][0][1] + dp[j + (1 << (i - 1))][i - 1][1][0]);
            dp[j][i][0][1] = min(dp[j][i - 1][0][0] + dp[j + (1 << (i - 1))][i - 1][0][1], dp[j][i - 1][0][1] + dp[j + (1 << (i - 1))][i - 1][1][1]);
            dp[j][i][1][0] = min(dp[j][i - 1][1][0] + dp[j + (1 << (i - 1))][i - 1][0][0], dp[j][i - 1][1][1] + dp[j + (1 << (i - 1))][i - 1][1][0]);
            dp[j][i][1][1] = min(dp[j][i - 1][1][0] + dp[j + (1 << (i - 1))][i - 1][0][1], dp[j][i - 1][1][1] + dp[j + (1 << (i - 1))][i - 1][1][1]);
        }
    }
    scanf("%lld", &m);
    while (m--)
    {
        pii s, e;
        scanf("%lld%lld%lld%lld", &s.first, &s.second, &e.first, &e.second);
        int sc = max(s.first, s.second);
        int ec = max(e.first, e.second);
        if(sc > ec) swap(sc, ec), swap(s, e);
        else if(sc == ec) {
            printf("%lld\n", abs(s.first - e.first) + abs(s.second - e.second));
            continue;
        }
        ec--;
        int ds[2], de[2];
        ds[0] = abs(doors[sc].first.first - s.first) + abs(doors[sc].first.second - s.second);
        ds[1] = abs(doors[sc].second.first - s.first) + abs(doors[sc].second.second - s.second);
        for (int b = 0; b < 2; ++b) {
            pii out;
            if (b == 0) out = {doors[ec].first.first + 1, doors[ec].first.second};
            else out = {doors[ec].second.first, doors[ec].second.second + 1};
            de[b] = 1 + abs(out.first - e.first) + abs(out.second - e.second);
        }
        int M[2][2] = {{0, INF}, {INF, 0}};
        int now = sc;
        int len = ec - sc;
        for (int i = 19; i >= 0; --i) {
            if (len >= (1 << i)) {
                int tmp[2][2];
                for (int a = 0; a < 2; ++a)
                    for (int b = 0; b < 2; ++b) {
                        tmp[a][b] = INF;
                        for (int k = 0; k < 2; ++k)
                            tmp[a][b] = min(tmp[a][b], M[a][k] + dp[now][i][k][b]);
                    }
                memcpy(M, tmp, sizeof(M));
                now += (1 << i);
                len -= (1 << i);
            }
        }
        int ans = INF;
        for (int a = 0; a < 2; ++a)
            for (int b = 0; b < 2; ++b)
                ans = min(ans, ds[a] + M[a][b] + de[b]);
        printf("%lld\n", ans);
    }
    return 0;
}