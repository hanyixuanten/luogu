#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
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
struct Mat
{
    long long a[26][26];
    Mat operator*(const Mat &B) {
        Mat C;
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                C.a[i][j] = INF;

        for (int i = 0; i < 26; ++i)
        {
            for (int t = 0; t < 26; ++t)
            {
                if (a[i][t] >= INF / 2)
                    continue;

                for (int j = 0; j < 26; ++j)
                {
                    if (B.a[t][j] >= INF / 2)
                        continue;

                    long long val = a[i][t] + B.a[t][j];
                    if (val < C.a[i][j])
                        C.a[i][j] = val;
                }
            }
        }
        return C;
    }
};
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        get(s[i]);
    get(l1);
    get(l2);
    get(l31);
    get(l32);
    init();
    Mat M;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            M.a[i][j] = INF;
    for (int j = 1; j <= n; ++j)
    {
        int fc = s[j][0] - 'a';
        int lc = s[j][s[j].size() - 1] - 'a';
        for (int c = 0; c < 26; ++c)
        {
            long long val = cost[j] + dis[c][fc];
            if (val < M.a[c][lc])
                M.a[c][lc] = val;
        }
    }
    Mat res; // 初始为单位矩阵
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            res.a[i][j] = (i == j ? 0 : INF);
    long long exp = k;
    while (exp > 0)
    {
        if (exp & 1LL)
            res = res * M;
        M = M * M;
        exp >>= 1LL;
    }

    long long ans = INF;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            ans = min(ans, res.a[i][j]);
    printf("%lld\n", ans);
    return 0;
}