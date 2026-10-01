#include <bits/stdc++.h>
using namespace std;
int pre[2000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + (s[i] == '1');
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len % 2 != 0) {
            cout << -1 << '\n';
            return 0;
        }
        int c = pre[r] - pre[l - 1];
        if (c != len / 2)
            ++ans;
    }
    cout << (ans + 1) / 2 << '\n';
    return 0;
}