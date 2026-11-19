#include <bits/stdc++.h>
using namespace std;
const int mod = 1024523;
int n, m;
char a[505], b[505];
struct modint{
    int num;
    const void operator=(int b){
        num = b % mod;
    }
    const void operator+=(modint b) {
        num = (1ll * num + b.num) % mod;
    }
};
modint f[2][505][505];
// 都取了i个，其中第一个人从第一根管子取了j个,第二个人从第一根管子取了k个
int main() {
    scanf("%d%d", &n, &m);
    for (int i = n; i >= 1; --i) {
        cin>>a[i];
        // scanf("%c", &a[i]);
    }
    for (int i = m; i >= 1; --i) {
        cin>>b[i];
        // scanf("%c", &b[i]);
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + m; ++i) {
        for (int j = 0; j <= min(i, n); ++j) {
            for (int k = 0; k <= min(i, n); ++k) {
                f[i & 1][j][k] = 0;
                if (a[j] == a[k] && j && k)
                    f[i&1][j][k] += f[(i - 1)&1][j - 1][k - 1];
                if (a[j] == b[i - k] && j)
                    f[i&1][j][k] += f[(i - 1)&1][j - 1][k];
                if (a[k] == b[i - j] && k)
                    f[i&1][j][k] += f[(i - 1)&1][j][k - 1];
                if (b[i - k] == b[i - j])
                    f[i&1][j][k] += f[(i - 1)&1][j][k];
            }
        }
    }
    printf("%d\n", f[(m + n)&1][n][n].num);
    return 0;
}