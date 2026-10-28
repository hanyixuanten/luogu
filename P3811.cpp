#include<bits/stdc++.h>
using namespace std;
long long n, p;
long long mul[3000005];
long long revs[3000005];
long long rev[3000005];
long long qpow(long long a, long long b) {
    a %= p;
    long long res = 1;
    while(b) {
        if(b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main() {
    scanf("%lld%lld", &n, &p);
    mul[0] = 1;
    for(int i = 1; i <= n; ++i) {
        mul[i] = (mul[i - 1] * i) % p;
    }
    revs[n] = qpow(mul[n], p - 2);
    for(int i = n - 1; i >= 1; --i) {
        revs[i] = ((i + 1) * revs[i + 1]) % p;
    }
    for(int i = 1; i <= n; ++i) {
        rev[i] = (mul[i - 1] * revs[i]) % p;
    }
    for(int i = 1; i <= n; ++i) {
        printf("%lld\n", rev[i]);
    }
    return 0;
}