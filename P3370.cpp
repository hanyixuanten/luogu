#include<bits/stdc++.h>
using namespace std;
int n;
unordered_map<string, int> m;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        m[s]++;
    }
    int ans = 0;
    for(auto a:m) ans++;
    printf("%d\n", ans);
    return 0;
}
