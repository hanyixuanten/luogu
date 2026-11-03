#include<bits/stdc++.h>
using namespace std;
const int mod = 1145141923;
int n, m;
int a[1000005];
unordered_map<int, bool> ma;
int _0;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]) {
            if(!ma[a[i]]) ma[a[i]] = 1;
            else {
                printf("0\n");
                return 0;
            }
        } else {
            _0++;
        }
    }
    long long ans = 1;
    for(int i = m - n + _0; i > m - n; --i) {
        ans = (ans * i) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}