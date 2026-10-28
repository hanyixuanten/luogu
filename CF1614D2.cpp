#include<bits/stdc++.h>
using namespace std;
int n;
const int maxa = 20000000;
vector<int> prime;
bool vis[20000005];
int cnt[20000005];
long long f[20000005];
int a[100005];
int main() {
    for (int i = 2; i <= 20000000; ++i) {
        if (!vis[i]) prime.push_back(i);
        for (int p : prime) {
            if (1ll * i * p > maxa) break;
            vis[i * p] = true;
            if (i % p == 0) break;
        }
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j * j <= a[i]; ++j) {
            if(a[i] % j == 0) {
                cnt[j]++;
                if(j * j != a[i]) ++cnt[a[i] / j]; 
            }
        }
    }
    for(int i = maxa; i >= 1; --i) {
        f[i] = 1ll * i * cnt[i];
        for(int j = 0; j < prime.size() && i * prime[j] <= maxa; ++j) {
            f[i] = max(f[i], f[i * prime[j]] + 1ll * i * (cnt[i] - cnt[i * prime[j]]));
        }
    }
    long long ans = 0;
    for(int i = 1; i <= maxa; ++i) {
        if(cnt[i] == n) {
            ans = max(ans, f[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}