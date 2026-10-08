#include <bits/stdc++.h>
using namespace std;
int n, s;
int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s);
        if (s == i)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}