#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<char> s[100005];
long long cost[100005];
vector<char> l1, l2, l31, l32;
int dis[30][30];
pair<int, int> rev[30];
void get(vector<char> &res)
{
    res.clear();
    char c = getchar_unlocked();
    while (c < 'a' || c > 'z')
        c = getchar_unlocked();
    while ('a' <= c && c <= 'z')
        res.push_back(c), c = getchar_unlocked();
}
int gdis(int a, int b)
{
    auto &pa = rev[a], &pb = rev[b];
    return abs(pa.first - pb.first) + abs(pa.second - pb.second);
}
void init()
{
    for (int i = 0; i < 9; ++i)
        rev[l1[i] - 'a'] = {1, i + 1};
    for (int i = 0; i < 9; ++i)
        rev[l2[i] - 'a'] = {2, i + 1};
    for (int i = 0; i < 4; ++i)
        rev[l31[i] - 'a'] = {3, i + 1};
    for (int i = 0; i < 4; ++i)
        rev[l32[i] - 'a'] = {3, i + 6};
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            dis[i][j] = gdis(i, j);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < (int)s[i].size(); ++j)
            cost[i] += gdis(s[i][j] - 'a', s[i][j - 1] - 'a');
}
const long long INF = 0x7f7f7f7f7f7f7f7fll;
long long dp[2][27];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        get(s[i]);
    get(l1);
    get(l2);
    get(l31);
    get(l32);
    init();
    int cur = 0;
    for (int i = 0; i < 26; ++i)
        dp[cur][i] = 0;
    for (int i = 1; i <= k; ++i)
    {
        int nxt = cur ^ 1;
        for (int x = 0; x < 26; ++x)
            dp[nxt][x] = INF;
        for (int j = 1; j <= n; ++j)
        {
            int fc = s[j][0] - 'a';
            int lc = s[j][s[j].size() - 1] - 'a';
            long long best = INF;
            for (int kk = 0; kk < 26; ++kk)
                best = min(best, dp[cur][kk] + gdis(kk, fc));
            dp[nxt][lc] = min(dp[nxt][lc], best + cost[j]);
        }
        cur = nxt;
    }

    long long ans = INF;
    for (int i = 0; i < 26; ++i)
        ans = min(ans, dp[cur][i]);
    printf("%lld\n", ans);
    return 0;
}