// 95
#include <bits/stdc++.h>
using namespace std;

int t;
int a[6];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            a[i] = 0;
            for (int j = 0; j < 5;)
            {
                int c = getchar();
                if (c == '0' || c == '1')
                {
                    if (c == '0')
                        a[i] |= 1 << (4 - j);
                    ++j;
                }
            }
        }
        int ans = 7;
        for (int fline = 0; fline < 32; ++fline)
        {
            int noww[5];
            for (int i = 0; i < 5; ++i)
                noww[i] = a[i];
            int pp[5] = {0};
            pp[0] = fline;
            noww[0] ^= pp[0];
            noww[0] ^= (pp[0] << 1) & 0x1F;
            noww[0] ^= (pp[0] >> 1);
            noww[1] ^= pp[0];
            for (int r = 1; r < 5; ++r)
            {
                pp[r] = noww[r - 1];
                noww[r] ^= pp[r];
                noww[r] ^= (pp[r] << 1) & 0x1F;
                noww[r] ^= (pp[r] >> 1);
                noww[r - 1] ^= pp[r];
                if (r < 4)
                    noww[r + 1] ^= pp[r];
            }

            bool flag = true;
            for (int i = 0; i < 5; ++i)
            {
                if (noww[i] != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                int cnt = 0;
                for (int i = 0; i < 5; ++i)
                    cnt += __builtin_popcount(pp[i]);
                if (cnt < ans)
                    ans = cnt;
            }
        }
        if (ans > 6)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}