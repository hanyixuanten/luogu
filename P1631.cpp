#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005], b[100005];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        q;
    for (int i = 1; i <= n; ++i)
        q.push({a[i] + b[1], {i, 1}});
    for (int i = 1; i <= n; ++i) {
        printf("%d ", q.top().first);
        auto t = q.top();
        q.pop();
        q.push({a[t.second.first] + b[t.second.second + 1],
                {t.second.first, t.second.second + 1}});
    }
    return 0;
}