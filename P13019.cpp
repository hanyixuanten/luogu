#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> chi[100005];
int fa[100005][25];
int minc[100005][25];
int q;
int a;
void pre(int now) {
    for(int i = 1; i <= 20; ++i) {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    for(int i : chi[now]) {
        pre(i);
    }
    for(int i = 1; i <= 20; ++i) {
        minc[now][i] = minc[minc[now][i - 1]][i - 1];
    }
}
int main() {
    scanf("%d%d", &n, &q);
    fa[1][0] = 1;
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &fa[i][0]);
        chi[fa[i][0]].push_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        minc[i][0] = INT_MAX;
        for(int j : chi[i]) {
            minc[i][0] = min(minc[i][0], j);
        }
        if(minc[i][0] == INT_MAX) minc[i][0] = i;
    }
    pre(1);
    while(q--) {
        int s, k;
        scanf("%d%d", &s, &k);
        for(int i = 1; i <= k; ++i) {
            scanf("%d", &a);
            if(a > 0) {
                for(int j = 20; j >= 0; --j) {
                    if(a >= (1 << j)) {
                        a -= (1 << j);
                        s = fa[s][j];
                    }
                }
            } else {
                a = -a;
                for(int j = 20; j >= 0; --j) {
                    if(a >= (1 << j)) {
                        a -= (1 << j);
                        s = minc[s][j];
                    }
                }
            }
        }
        // printf("111: %d\n", fa[5][0]);
        printf("%d\n", s);
    }
    return 0;
}