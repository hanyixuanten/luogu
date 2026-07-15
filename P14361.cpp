#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        vector<int> diffs[3];
        int n, total = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int val[3];
            for (int j = 0; j < 3; j++)
                scanf("%d", &val[j]);
            int best = 0;
            for (int j = 1; j < 3; j++)
                if (val[j] > val[best])
                    best = j;
            total += val[best];
            int second = (best == 0) ? 1 : 0;
            for (int j = 0; j < 3; j++)
                if (j != best && val[j] > val[second])
                    second = j;
            diffs[best].push_back(val[best] - val[second]);
        }
        for (int i = 0; i < 3; i++)
        {
            if ((int)diffs[i].size() > n / 2)
            {
                sort(diffs[i].begin(), diffs[i].end());
                int drop = (int)diffs[i].size() - n / 2;
                for (int j = 0; j < drop; j++)
                    total -= diffs[i][j];
            }
        }
        printf("%d\n", total);
    }
    return 0;
}