#include<bits/stdc++.h>
using namespace std;
int n,m;
long long tree[500005];
long long a[500005];
int lowbit(int n){
    return n&(-n);
}
void modify(int x,long long k)
{
	for(;x<=n;x+=lowbit(x))
		tree[x]+=k; 
}
long long query(int x){
    int ans;
    for(;x;x-=lowbit(x))
        ans=ans+tree[x];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        modify(i,a[i]);
    }
    while(m--){
        int op,x;
        long long y;
        scanf("%d%d%lld",&op,&x,&y);
        if(op==1) modify(x,y);
        else printf("%lld\n",query(y)-query(x-1));
    }
    return 0;
}