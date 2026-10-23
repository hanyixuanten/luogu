#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005];
int xl[100005];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            xl[i] = a[i];
        }
        sort(a + 1, a + n + 1);
        int tot = unique(a + 1, a + n + 1) - a;
        for(int i = 1; i <= n; ++i) {
            int wher = lower_bound(a + 1, a + tot, xl[i]) - a;
            printf("%d ",wher);
        }
        printf("\n");
    }
}