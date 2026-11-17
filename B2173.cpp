#include<bits/stdc++.h>
using namespace std;
int n, v;
struct node{
    int w, v, c;
}obj[505];
int f[1005];
int main() {
    scanf("%d%d", &n, &v);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &obj[i].w, &obj[i].v, &obj[i].c);
    }
    for(int i = 1; i <= n; ++i)
        for(int k = 1; k <= obj[i].c; ++k)
            for(int j = v; j >= obj[i].w; --j)
                f[j] = max(f[j], f[j - obj[i].w] + obj[i].v);
    printf("%d\n", f[v]);
    return 0;
}