#include<bits/stdc++.h>
using namespace std;
int t;
int fa[30005];
int dep[30005]; // 表示到fa的距离
int len[30005]; // 表示最大深度
int find(int x)
{
	if (fa[x] == x) return x;
	int father = find(fa[x]);
	dep[x] += dep[fa[x]];
	fa[x] = father;
	return father;
}

int main() {
    scanf("%d", &t);
    for(int i = 1; i <= 30000; ++i) {
        fa[i] = i, len[i] = 1;
    }
    while(t--) {
        char op;
        int i, j;
        scanf("\n%c%d%d", &op, &i, &j);
        if(op == 'M') {
            int fi = find(i), fj = find(j);
            fa[fi] = find(j);
            dep[fi] += len[fj];
            len[fj] += len[fi];
        } else {
            if(find(i) != find(j)) {
                printf("-1\n");
            } else {
                printf("%d\n", abs(dep[i] - dep[j]) - 1);
            }
        }
    }
    return 0;
}