#include <bits/stdc++.h>
using namespace std;
int n, k, q, d[1000005], f[1000005];
typedef pair<int, int> pii;
pair<int, int> qq[4000005];
int lq = 1, rq = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &k);
		lq = 1, rq = 1;
		qq[1] = {0, 1};
        for(int i = 2; i <= n; ++i) {
			while(lq <= rq && qq[lq].second < i - k) ++lq;
            f[i] = qq[lq].first + (d[qq[lq].second] <= d[i]);
            while(lq <= rq && (qq[rq].first > f[i] || (qq[rq].first == f[i] && d[qq[rq].second] <= d[i]))) --rq;
            qq[++rq] = {f[i], i};
        }
        printf("%d\n", f[n]);
    }
}
