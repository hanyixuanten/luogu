#include<bits/stdc++.h>
using namespace std;
int t,k;
int n;
char s[200005];
int main(){
    scanf("%d%d",&t,&k);
    while(t--){
        scanf("%d%s",&n,s);
        bool flag=0;
        vector<char> ans;
        for(int i=n-1;i>=0;--i){
            if((s[i]=='O'&&!flag) || (s[i]=='M' &&flag)){
                ans.push_back('O');
                flag=!flag;
            }else{
                ans.push_back('M');
            }
        }
        puts("YES");
        if(k==1){
            for(int i=n-1;i>=0;--i){
                putchar(ans[i]);
            }
            puts("");
        }
    }
    return 0;
}
/*
MOO
MOO
*/