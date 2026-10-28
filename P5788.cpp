#include<bits/stdc++.h>
using namespace std;
int n;
int a[3000005];
int stk[3000005];
int top = 0;
int ans[3000005];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = n; i >= 1; --i) {
        while(top > 0 && a[stk[top]] <= a[i]) top--;
        stk[++top] = i;
        ans[i] = stk[top - 1];
    }
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}