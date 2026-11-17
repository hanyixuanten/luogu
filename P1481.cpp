#include<bits/stdc++.h>
using namespace std;
int n;
char s[75];
int len;
struct trie{
    vector<trie*> chi;
    char c;
    int cnt = 0;
};
void add(trie *now, int l) {
    if(l > len) {
        now->cnt++;
        return;
    }
    bool flag = 0;
    for(auto v : now->chi) {
        if(v->c == s[l]) {
            add(v, l + 1);
            flag = 1;
            break;
        }
    }
    if(!flag) {
        trie *nc = new trie;
        now->chi.push_back(nc);
        nc->c = s[l];
        add(nc, l + 1);
    }
}
int maxans = 0;
void dfs(trie *now, int cnt) {
    maxans = max(maxans, cnt + now->cnt);
    for(auto v : now->chi) {
        dfs(v, cnt + now->cnt);
    }
}
int main() {
    trie *root = new trie;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        len = strlen(s + 1);
        add(root, 1);
    }
    dfs(root, 0);
    printf("%d\n", maxans);
    return 0;
}