#include<bits/stdc++.h>
using namespace std;
int n,k;
int cs[25][25][25];
int calc(int now){
    int ans=0;
    for(int i=0;i<n;i++){
        if(!(now&(1<<i))) continue;
        for(int j=0;j<n;j++){
            if((now&(1<<j))) continue;
            for(int k=j;k<n;k++){
                if(!(now&(1<<k))){
                    ans+=cs[i][j][k];
                }
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--,y--,z--;
        if(y>z) swap(y,z);
        cs[x][y][z]++;
    }
    int maxans=0,count=0;
    for(int i=0;i<=(1<<n)-1;i++){ // 二进制表示棋盘
        int ci=calc(i);
        if(ci>maxans) count=1, maxans=ci;
        else if(ci==maxans) count++;
    }
    printf("%d %d\n",maxans,count);
    return 0;
}