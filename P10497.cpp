#include<bits/stdc++.h>
using namespace std;
int n;
int a[8006];
bool vis[8006];
int num[8006];
int main() {
    scanf("%d", &n);
    vis[1] = 1;
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &a[i]);
        vis[i] = 1;
    }
    for(int i = n; i >= 1; --i) {
        int s = 0;
        for(int j = 1; j <= n; ++j) {
            s += vis[j];
            if(s == a[i] + 1) {
                num[i] = j;
                vis[j] = 0;
                break;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d\n", num[i]);
    }
    return 0;
}
/*
在 vis 数组中进行查找一个最小的位置，满足前缀和为 a+1。
*/