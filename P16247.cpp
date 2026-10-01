#include <bits/stdc++.h>
using namespace std;
long long a[15][15];
int main() {
    long long ans = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 13; ++j) {
            a[i][j] = i * j * (i + j);
            if (i == j)
                a[i][j] *= 2;
            if (i == 1 || j == 1 || i == 13 || j == 13)
                a[i][j] /= 2;
            ans += a[i][j];
        }
    }
    cout << ans + 100;
    return 0;
}