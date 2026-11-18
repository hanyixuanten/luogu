#include<bits/stdc++.h>
using namespace std;
int n;
int a[2005];
priority_queue<int> pq;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0, ans2 = 0;
    for(int i = 1; i <= n; ++i) {
        pq.push(a[i]);
        if(a[i] < pq.top()) {
            ans += pq.top() - a[i];
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty()) pq.pop();
    for(int i = n; i >= 1; --i) {
        pq.push(a[i]);
        if(a[i] < pq.top()) {
            ans2 += pq.top() - a[i];
            pq.pop();
            pq.push(a[i]);
        }
    }
    printf("%d\n", min(ans, ans2));
    return 0;
}