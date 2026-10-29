#include<bits/stdc++.h>
using namespace std;
long long a;
int minans = INT_MAX;
int n;
void dfs(int now, int pre_k, long long now_a) {
    if(now > 6 || now >= minans) {
        return;
    }
    if(now_a == (1ll << n) - 1) {
        minans = min(minans, now);
    }
    for(int k = pre_k; k <= n; ++k) {
        long long new_a = now_a | (now_a >> k);
        if(new_a > now_a) dfs(now + 1, k, new_a);
    }
}
int main() {
    char s[45];
    scanf("%s", s + 1);
    if(s[1] == '0') {
        printf("-1\n");
        return 0;
    }
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++i) {
        a *= 2;
        if(s[i] == '1') a += 1;
    }
    dfs(0, 1, a);
    printf("%d\n", minans);
    return 0;
}