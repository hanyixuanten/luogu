#include <bits/stdc++.h>
using namespace std;
int side(char c) {
    if (c == 'A' || c == 'B' || c == 'C') return 0;
    return 1;
}
int pos(char c) {
    if (c == 'A') return 0;
    if (c == 'B') return 1;
    if (c == 'C') return 2;
    if (c == 'D') return 0;
    return 1; // 'F'
}
int main() {
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool ans1 = (c1 == c2);
    bool ans2 = ans1 && (s1.substr(0, 2) == s2.substr(0, 2));
    char a = s1[2], b = s2[2];
    bool ans3 = ans2 && (side(a) == side(b));
    bool ans4 = ans3 && (abs(pos(a) - pos(b)) == 1);
    cout << ans1 << ans2 << ans3 << ans4 << '\n';
    return 0;
}