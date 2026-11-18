#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        vector<int> cuts;
        cuts.push_back(0);
        for (int i = 0; i < n; ++i)
        {
            if (i == n - 1 || a[i] != a[i + 1])
                cuts.push_back(i + 1);
        }
        int mx = 1;
        while (mx < n)
            mx <<= 1;
        int ans = INT_MAX;
        for (int A = 1; A <= mx; A <<= 1)
        {
            for (int B = 1; B <= mx; B <<= 1)
            {
                for (int C = 1; C <= mx; C <<= 1)
                {
                    int L = n - C;
                    auto it = upper_bound(cuts.begin(), cuts.end(), A);
                    --it;
                    int i = *it;
                    bool ok = 0;
                    if (i >= L)
                        ok = 1;
                    else
                    {
                        auto jt = lower_bound(cuts.begin(), cuts.end(), L);
                        if (jt != cuts.end() && *jt <= i + B)
                            ok = 1;
                    }
                    if (ok)
                        ans = min(ans, A + B + C - n);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
