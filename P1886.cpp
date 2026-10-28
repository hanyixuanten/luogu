#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[1000005];
pair<int, int> minq[4000005];
pair<int, int> maxq[4000005];
int lq = 1, rq = 0;
int lqq = 1, rqq = 0;
void push(pair<int, int> now) {
    while(lq <= rq && maxq[lq].second <= now.second - k) ++lq;
    while(lq <= rq && maxq[rq].first < now.first) --rq;
    maxq[++rq] = now;

    while(lqq <= rqq && minq[lqq].second <= now.second - k) ++lqq;
    while(lqq <= rqq && minq[rqq].first > now.first) --rqq;
    minq[++rqq] = now;
}
int maxx[1000005];
int minn[1000005];
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= k; ++i) {
        push(make_pair(a[i], i));
    }
    maxx[1] = maxq[lq].first;
    minn[1] = minq[lqq].first;
    for(int l = 2; l + k - 1 <= n; ++l) {
        int r = l + k - 1;
        push(make_pair(a[r], r));
        maxx[l] = maxq[lq].first;
        minn[l] = minq[lqq].first;
    }
    for(int i = 1; i + k - 1 <= n; ++i) printf("%d ", minn[i]);
    printf("\n");
    for(int i = 1; i + k - 1 <= n; ++i) printf("%d ", maxx[i]);
    return 0;
}