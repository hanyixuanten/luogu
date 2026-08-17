// 118
#include <bits/stdc++.h>
using namespace std;
int n;
bool a[1000][1000];
void cal(int n, int x, int y)
{
    if (n == 1)
    {
        a[x][y] = 1;
        return;
    }
    /*
X X   X X
 X     X
X X   X X
   X X
    X
   X X
X X   X X
 X     X
X X   X X
    */
    int m = pow(3, n - 2);
    cal(n - 1, x, y);
    cal(n - 1, x, y + 2*m);
    cal(n - 1, x + m, y+m);
    cal(n - 1, x + 2 * m, y);
    cal(n - 1, x + 2 * m, y + 2*m);
}
int main()
{
    while (cin >> n)
    {
        memset(a, 0, sizeof a);
        if (n < 0)
            break;
        cal(n, 0, 0);
        for (int i = 0; i < pow(3,n-1); ++i)
        {
            for (int j = 0; j < pow(3,n-1); ++j)
            {
                if (a[i][j] == 1)
                    putchar('X');
                else
                    putchar(' ');
            }
            putchar('\n');
        }
        puts("-");
    }
    return 0;
}