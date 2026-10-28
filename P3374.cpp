#include<bits/stdc++.h>
using namespace std;
inline int lowbit(int x) {return x & (-x);};
int n, m;
int a[500005];
int num[500005];
void add(int now, int nn) {
    for(; now <= n; now += lowbit(now)) num[now] += nn;
}
int query(int now) {
    int res = 0;
    for(; now; now -= lowbit(now)) res += num[now];
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), add(i, a[i]);
    while(m--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1) {
            add(x, y);
        } else{
            printf("%d\n", query(y) - query(x - 1));
        }
    }
    return 0;
}