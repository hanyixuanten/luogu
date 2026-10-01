#include <bits/stdc++.h>
using namespace std;
int t;
int n; // 2000
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) {
                    printf("%d ", i);
                } else if (i % j == 0) {
                    printf("%d ", j);
                } else if (j % i == 0) {
                    printf("%d ", i);
                } else {
                    printf("1 ");
                }
            }
            putchar('\n');
        }
    }
    return 0;
}