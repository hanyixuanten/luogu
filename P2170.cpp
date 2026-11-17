#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[20005];
int cnt[20005];
bitset<40005> cann;
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= k; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        fa[find(u)] = find(v);
    }
    for(int i = 1; i <= n; ++i) {
        cnt[find(i)]++;
    }
    cann[0] = 1;
    for(int i = 1; i <= n; ++i) {
        cann |= (cann << cnt[i]);
    }
    for(int i = 0; i <= n; ++i) {
        if(m >= i && cann[m - i]) {
            printf("%d\n", m - i);
            return 0;
        }
        if(m + i <= n && cann[m + i]) {
            printf("%d\n", m + i);
            return 0;
        }
    }
    return 0;
}