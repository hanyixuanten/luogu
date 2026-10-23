#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
    x = 0;
    bool fu = 0;
    char c = getchar_unlocked();
    while ((c < '0' || c > '9') && c != '-')
        c = getchar_unlocked();
    if(c=='-') fu=1, c=getchar_unlocked();
    while (c>='0' && c<='9'){
        x = 10*x+c-'0', c = getchar_unlocked();
    }
    x=((fu)?-1:1)*x;
}
int main(){
    int n, ans=0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x;
        read(x);
        ans+=x;
    }
    printf("%d\n", ans);
    return 0;
}