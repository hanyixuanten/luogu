#include <bits/stdc++.h>
using namespace std;
int t;
int n, q;
struct node{
    vector<node*> child;
    char c;
    int cnt = 0;
    int childsize = 0;
};
char s[3000005];
int len;
void add(node *now, int i) {
    now -> childsize++;
    if(i == len) {
        now -> cnt++;
        return;
    }
    // if(now -> c == ' ') {
    bool flag = 0;
    for(auto c : now -> child) {
        if(c -> c == s[i]) {
            add(c, i + 1);
            flag = 1;
            break;
        }
    }
    if(!flag) {
        node *nc = new node;
        nc -> c = s[i];
        now->child.push_back(nc);
        add(nc, i + 1);
    }
    // }
}
int query(node *now, int i) {
    if(i == len) {
        return now -> childsize;
    }
    for(auto c : now -> child) {
        if(c -> c == s[i]) {
            return query(c, i + 1);
        }
    }
    return 0;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        node *root = new node;
        // root -> c=' ';
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s + 1);
            len = strlen(s + 1) + 1;
            add(root, 1);
        }
        for(int i = 1; i <= q; ++i) {
            scanf("%s", s + 1);
            len = strlen(s + 1) + 1;
            printf("%d\n", query(root, 1));
        }
    }
    return 0;
}