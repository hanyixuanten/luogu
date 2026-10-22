#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, t;
signed main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n == 0) {
            printf("NO!\n");
            continue;
        }
        int cnt = 0;
        while (n % 2 == 0)
            n /= 2, cnt++;
        printf("%lld\n", cnt + 1);
    }
    return 0;
}
/*
1.5*2
2.5*3*8
3.5*4
4.5*5*23*

奇数.5
0.5 * n = 奇数
*/