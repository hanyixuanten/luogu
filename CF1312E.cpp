#include<bits/stdc++.h>
using namespace std;
int n, a[510], dp[510][510], w[510][510];
int main(){
    memset(dp, 0x7f, sizeof(dp));
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++)
        scanf("%d" , &a[i]) , dp[i][i] = 1 , w[i][i] = a[i];
    for(int len = 2; len <= n; len++)
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for(int mid = l; mid < r; mid++){
                dp[l][r] = min(dp[l][r] , dp[l][mid] + dp[mid + 1][r]);
                if(dp[l][mid] == dp[mid + 1][r] && dp[l][mid] == 1 && w[l][mid] == w[mid + 1][r])
                    dp[l][r] = 1 , w[l][r] = w[l][mid] + 1;
            }
        }
    printf("%d" , dp[1][n]);
    return 0;
}
