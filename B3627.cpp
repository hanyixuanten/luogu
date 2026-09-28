#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    scanf("%lld",&n);
    long double l=1,r=n,mid=(l+r)/2;
    while(r-l>=1e-6){
        mid=(l+r)/2;
        if(mid*mid*mid<n){
            l=mid;
        }else{
            r=mid;
        }
    }
    long long ans = mid;
    printf("%lld\n",ans);
    return 0;
}