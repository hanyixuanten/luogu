#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 19260817;
signed main() {
    auto read = [](int &x) {
        x = 0;
        char c = getchar();
        while (c < '0' || c > '9')
            c = getchar();
        while (c >= '0' && c <= '9')
            x = (x * 10 + c - '0') % mod, c = getchar();
    };
    auto qpow = [](int a, int b) {
        a %= mod;
        int ans = 1;
        while (b) {
            if (b & 1)
                ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    };
    int a, b;
    read(a), read(b);
    if (a == 0 || b == 0)
        printf("Angry!\n");
    else
        printf("%lld\n", (a * qpow(b, mod - 2)) % mod);
    return 0;
}