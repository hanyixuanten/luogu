#include <bits/stdc++.h>
using namespace std;
int n, N;
map<int, int> changes;
int main() {
    scanf("%d%d", &n, &N);
    for (int i = 1, a; i <= n; ++i)
        scanf("%d", &a), changes[a] = 1;
    for (int i = 1; i * (N / (n + 1)) < N; i++) {
        if (changes.find(i * (N / (n + 1))) != changes.end())
            changes[i * (N / (n + 1))] = 3;
        else
            changes[i * (N / (n + 1))] = 2;
    }
    changes[N] = 2;
    int nowf = 0, nowg = 0;
    long long ans = 0;
    pair<int, int> pre = {0, 0};
    for (pair<int, int> now : changes) {
        ans += abs(nowg - nowf) * (now.first - pre.first);
        if (now.second == 1)
            nowf++;
        else if (now.second == 2)
            nowg++;
        else
            nowf++, nowg++;
        pre = now;
    }
    printf("%lld\n", ans);
    return 0;
}