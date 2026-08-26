#include <bits/stdc++.h>
using namespace std;
int a, b;
int dp[15][15];
int getlen(int num)
{
    if (num < 10)
        return 1;
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}
int calc(int x)
{
    if (x <= 0)
        return 0;
    vector<int> digit;
    while (x)
    {
        digit.push_back(x % 10);
        x /= 10;
    }
    int len = digit.size();
    int res = 0;
    for (int i = 1; i < len; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            res += dp[i][j];
        }
    }
    for (int i = len - 1; i >= 0; --i)
    {
        int cur = digit[i];
        int start = (i == len - 1) ? 1 : 0;
        for (int j = start; j < cur; ++j)
        {
            if (i == len - 1 || abs(j - digit[i + 1]) >= 2)
            {
                if (i == 0)
                {
                    ++res;
                }
                else
                {
                    res += dp[i + 1][j];
                }
            }
        }
        if (i != len - 1 && abs(cur - digit[i + 1]) < 2)
        {
            break;
        }
        if (i == 0)
        {
            ++res;
        }
    }
    return res;
}

int main()
{
    scanf("%d%d", &a, &b);
    int _b = getlen(b);
    for (int i = 0; i <= 9; ++i)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= _b; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            for (int k = 0; k <= 9; ++k)
            {
                if (abs(j - k) < 2)
                    continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    printf("%d\n", calc(b) - calc(a - 1));
    return 0;
}