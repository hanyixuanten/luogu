#include <bits/stdc++.h>
using namespace std;
int n;
long long a, r, m;
int h[100005];
long long sum = 0;

long long check(long long now) {
    long long add = 0, del = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] < now) {
            add += now - h[i];
        } else {
            del += h[i] - now;
        }
    }
    long long move = min(add, del);
    return move * m + (add - move) * a + (del - move) * r;
}

int main() {
    scanf("%d%lld%lld%lld", &n, &a, &r, &m);
    if (m > a + r)
        m = a + r;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]), sum += h[i];
    sort(h + 1, h + n + 1);
    long long l = 0, r = 1e9;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid) <= check(mid + 1)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", check(l));
    return 0;
}