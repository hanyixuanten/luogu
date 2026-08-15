// 113
#include <bits/stdc++.h>
using namespace std;
// --- down for luogu ---
bool compare(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    bool t;
    cin >> t;
    return t;
}
// --- up for luogu ---
class Solution
{
public:
    vector<int> tmp, a;
    int tot = 0;
    void ms(int l, int r)
    {
        if (l == r)
            return;
        int mid = l + r >> 1;
        ms(l, mid);
        ms(mid + 1, r);
        int i = l, j = mid + 1, tot = l;
        while (i <= mid && j <= r)
            if (compare(a[i], a[j]))
                tmp[tot++] = a[i++];
            else
                tmp[tot++] = a[j++];
        while (i <= mid)
            tmp[tot++] = a[i++];
        while (j <= r)
            tmp[tot++] = a[j++];
        for (int k = l; k <= r; ++k)
            a[k] = tmp[k];
    }
    vector<int> specialSort(int N)
    {
        a.resize(1005);
        tmp.resize(1005);
        for (int i = 1; i <= N; ++i)
        {
            a[i] = i;
        }
        ms(1, N);
        vector<int> res(N);
        for (int i = 0; i < N; ++i)
        {
            res[i] = a[i + 1];
        }
        return res;
    }
};
// --- down for luogu ---
int main()
{
    int n;
    scanf("%d", &n);
    Solution k;
    vector<int> ans = k.specialSort(n);
    printf("! ");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
// --- up for luogu ---