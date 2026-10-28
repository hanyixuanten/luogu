#include<bits/stdc++.h>
using namespace std;
char s1[1000006], s2[1000006];
int n1, n2;
int nxt[1000006];
void gnext() {
    for(int i = 2; i <= n2; ++i) {
        int j = nxt[i - 1];
        while(j > 0 && s2[j + 1] != s2[i]) j = nxt[j];
        if(s2[j + 1] == s2[i]) j++;
        nxt[i] = j;
    }
}
void f() {
    int j = 0;
    for(int i = 1; i <= n1; ++i) {
        while(j > 0 && s2[j + 1] != s1[i]) j = nxt[j];
        if(s2[j + 1] == s1[i]) j++;
        if(j == n2) {
            printf("%d\n", i - n2 + 1);
            j = nxt[j];
        }
    }
}
int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
    gnext();
    f();
    for(int i = 1; i <= n2; ++i) {
        printf("%d ", nxt[i]);
    }
    return 0;
}