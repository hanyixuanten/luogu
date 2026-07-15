#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 5;
const int MAX_XOR = 2e6 + 5e5 + 5;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] ^ a[i];
    }

    vector<int> last_pos(MAX_XOR, -1);
    last_pos[0] = 0;

    int ans = 0, seg_start = 0;
    for (int r = 1; r <= n; r++)
    {
        int target = pre[r] ^ k;
        if (last_pos[target] >= seg_start)
        {
            ans++;
            seg_start = r;
        }
        last_pos[pre[r]] = r;
    }

    printf("%d\n", ans);
    return 0;
}