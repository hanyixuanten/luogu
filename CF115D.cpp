#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000003;
const int MAXN = 2005;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c;
    int i = 0;
    bool first = 1;
    while (i < n) {
        string op;
        while (i < n && !isdigit(s[i])) {
            op += s[i];
            i++;
        }
        if (i >= n) {
            if (!op.empty()) {// 字符串以运算符结尾
                cout << 0 << endl;
                return 0;
            }
            break;
        }
        while (i < n && isdigit(s[i]))
            i++;
        if (first) {
            for (char ch : op) {
                if (ch != '+' && ch != '-') {
                    cout << 0 << endl;
                    return 0;
                }
            }
            c.push_back(op.size());
            first = 0;
        } else {
            if (op.empty()) {
                cout << 0 << endl;
                return 0;
            }
            char fc = op[0];
            if (fc != '+' && fc != '-' && fc != '*' &&
                fc != '/') {
                cout << 0 << endl;
                return 0;
            }
            for (int j = 1; j < (int)op.size(); j++) {
                if (op[j] != '+' && op[j] != '-') {
                    cout << 0 << endl;
                    return 0;
                }
            }
            c.push_back(op.size() - 1);
        }
    }
    if (c.empty()) {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> dp(MAXN, 0), ndp(MAXN, 0);
    dp[0] = 1;
    int m = c.size();
    for (int idx = 0; idx < m; idx++) {
        int ci = c[idx];
        int r = ci + 1;
        for (int k = 0; k < r; k++) {
            for (int j = 1; j < MAXN; j++) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
        if (idx != m - 1) {
            fill(ndp.begin(), ndp.end(), 0);
            for (int j = 1; j < MAXN; j++) {
                ndp[j - 1] = dp[j];
            }
            dp = ndp;
        }
    }
    cout << dp[0] % MOD << endl;
    return 0;
}