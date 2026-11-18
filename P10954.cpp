#include<bits/stdc++.h>
using namespace std;
int n;
int a[3005];
int b[3005];
int f[3005][3005];
int ans = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(a[i] != b[j]) f[i][j] = f[i - 1][j];
            else {
                int mx = 0;
				for(int k = 1; k < j; ++k)
					if(b[k] < b[j]) mx = max(mx, f[i - 1][k]);
				f[i][j] = mx + 1;
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}