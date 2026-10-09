#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> dro[10];
bool used[10];
double siz;
double r[10];
int x, y, xx, yy;
double calc(int a, int b) {
    return sqrt((dro[a].first - dro[b].first) * (dro[a].first - dro[b].first) +
                (dro[a].second - dro[b].second) *
                    (dro[a].second - dro[b].second)) -
           r[b];
}
double ans = 4e6;
void dfs(int now, int cnt) {
    used[now] = 1;
    double maxd = min(min(abs(dro[now].first - x), abs(dro[now].first - xx)),
                      min(abs(dro[now].second - y), abs(dro[now].second - yy)));
    for (int i = 1; i <= n; ++i) {
        if (used[i] && i != now)
            maxd = min(maxd, calc(now, i));
    }
    if (maxd < 0)
        maxd = 0;
    r[now] = maxd;
    siz -= 3.1415926 * maxd * maxd;
    if (cnt == n) {
        ans = min(ans, siz);

    } else {
        for (int i = 1; i <= n; ++i) {
            if (!used[i])
                dfs(i, cnt + 1);
        }
    }
    siz += 3.1415926 * maxd * maxd;
    used[now] = 0;
}
int main() {
    scanf("%d", &n);
    scanf("%d%d%d%d", &x, &y, &xx, &yy);
    x += 1000, y += 1000, xx += 1000, yy += 1000;
    siz = abs((x - xx) * (y - yy));
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &dro[i].first, &dro[i].second);
        dro[i].first += 1000, dro[i].second += 1000;
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, 1);
    }
    printf("%.0lf\n", ans);
    return 0;
}