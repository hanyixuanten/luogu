#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
int n;
vector<int> fri[5005];
int H[5005];
int f[5005][5005];
int siz[5005];
int tmp[5005];
void dfs(int u, int from) {
    siz[u] = 1;
    f[u][1] = 1;
    for(int v : fri[u]) {
        if(v == from) continue;
        dfs(v, u);
        for(int i = 1; i <= siz[u] + siz[v]; ++i) tmp[i] = 0;
		for(int i = 1; i <= siz[u]; ++i){
			for(int j = 1; j <= siz[v]; ++j){
				tmp[i] = (1ll * tmp[i] + mod - 1ll * (f[u][i] * f[v][j]) % mod * H[j]) % mod;
				tmp[i + j] = (tmp[i + j] + 1ll * f[u][i] * f[v][j]) % mod;
			}
		}
		for(int i = 1; i <= siz[u] + siz[v]; ++i) f[u][i] = tmp[i];
		siz[u] += siz[v];
    }
}
signed main() {
    H[0] = 1;
    for(int i = 2; i <= 5000; i += 2) {
        H[i] = (H[i - 2] * (i - 1ll)) % mod;
    }
    scanf("%lld", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%lld%lld", &u, &v);
        fri[u].push_back(v);
        fri[v].push_back(u);
    }
    dfs(1, 0);
    long long ans = 0;
	for(int i = 1; i <= n; ++i) ans = (ans + 1ll * f[1][i] * H[i] % mod) % mod;
	printf("%lld\n", ans);
    return 0;
}