#include <bits/stdc++.h>
using namespace std;
int n;
char s[55][105];
int lens[55];
char inp[105];
int leninp;
char buf[50];
int main() {
    for (int i = 1; i <= 32; i++)
        buf[i] = '*';
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        lens[i] = strlen(s[i] + 1);
    }
    scanf("%s", inp + 1);
    leninp = strlen(inp + 1);
    for (int i = 1; i <= n; ++i) {
        bool flag = 0;
        for (int j = 1; j <= leninp; j++) {
            if (s[i][j] != inp[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            buf[s[i][leninp + 1] - 'A' + 4] = s[i][leninp + 1];
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 8; j++) {
            putchar(buf[8 * (i - 1) + j]);
        }
        putchar('\n');
    }
    return 0;
}