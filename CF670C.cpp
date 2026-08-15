// 103
#include <bits/stdc++.h>
using namespace std;
int n, m;                            // 200000
int a[200005], b[200005], c[200005]; // bi!=ci
map<int, int> hui;
pair<pair<int, int>, int> happy[200005];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.first != b.first.first)
    {
        return a.first.first > b.first.first;
    }
    else
        return a.first.second > b.first.second;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        hui[a[i]]++;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]), happy[i].first.first = hui[b[i]], happy[i].second = i;
    for (int i = 1; i <= m; ++i)
        scanf("%d", &c[i]), happy[i].first.second = hui[c[i]];
    sort(happy + 1, happy + m + 1, cmp);
    printf("%d\n", happy[1].second);
    return 0;
}