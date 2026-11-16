#include<bits/stdc++.h>
using namespace std;
char s[15][15];
vector<pair<int, int>> _0;
bool flag = 0;
void dfs(int now) {
    if(now == (int)_0.size()) {
        flag = 1;
        for(int i = 1; i <= 9; ++i) {
            for(int j = 1; j <= 9; ++j) {
                printf("%c", s[i][j] + '0');
            }
            printf("\n");
        }
        return;
    }
    auto [x, y] = _0[now];
    bitset<15> used;
    for(int i = 1; i <= 9; ++i) {
        used[s[i][y]] = 1;
    }
    for(int i = 1; i <= 9; ++i) {
        used[s[x][i]] = 1;
    }
    int lx, uy;
    if(x <= 3) lx = 1;
    else if(x <= 6) lx = 4;
    else lx = 7;
    if(y <= 3) uy = 1;
    else if(y <= 6) uy = 4;
    else uy = 7;
    for(int i = lx; i < lx + 3; ++i) {
        for(int j = uy; j < uy + 3; ++j) {
            used[s[i][j]] = 1;
        }
    }
    vector<int> can;
    for(int i = 1; i <= 9; ++i) {
        if(!used[i]) can.push_back(i);
    }
    for(int i:can) {
        s[x][y] = i;
        dfs(now + 1);
        if(flag) return;
    }
    s[x][y] = 0;
}
int t;
int main() {
    scanf("%d", &t);
    while(t--){
        for(int i = 1; i <= 9; ++i) {
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= 9; ++j) {
                s[i][j] -= '0';
                if(s[i][j] == 0) _0.push_back({i, j});
            }
        }
        dfs(0);
        flag = 0;
        _0.clear();
    }
    return 0;
}