#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long qsum[500005];
bool checkb(int mid, long long now, int tot) {
    return mid * now - (qsum[tot] - qsum[tot - mid]) <= m;
}
long long check(long long now, int tot) {
    long long nowm = m;
    long long ans = 0;
    int l = 1, r = tot, mid = (l + r) >> 1;
    while(l < r) {
        mid = (l + r) >> 1;
        if(checkb(mid, now, tot)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    while(!checkb(mid, now, tot) && mid >= 1) mid--;
    while(checkb(mid + 1, now, tot) && mid + 1 <= tot) mid++;
    return mid;
}
int main() {
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) qsum[i] = qsum[i - 1] + a[i];
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i + 1] == a[i]) continue;
        ans = max(ans, check(a[i], i));
        // printf("%d %lld\n", i, check(a[i], i));
    }
    printf("%lld\n", ans);
    return 0;
}
/*
g++ crystal/crystal.cpp -o crystal/crystal -std=c++14 -O2 -static -Wall && cp crystal/crystal ~ && chmod +x ~/crystal && ~/crystal
O(n log n)
100pts
*/