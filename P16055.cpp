#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, double>> o;
double st1[200005][21], st2[200005][21];
int main() {
    scanf("%d%d", &n, &m);
    o.push_back({0, 0});
    for (int i = 1; i <= n; ++i) {
        int op;
        double k;
        scanf("%d%lf", &op, &k);
        o.push_back({op, k});
        if (op == 1) {
            st1[i][0] = k;
            st2[i][0] = 0;

        } else {
            st1[i][0] = cos(k);
            st2[i][0] = sin(k);
        }
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            double tmp11 = st1[j][i - 1], tmp12 = st2[j][i - 1];
            double tmp21 = st1[j + (1 << (i - 1))][i - 1],
                tmp22 = st2[j + (1 << (i - 1))][i - 1];
            st1[j][i] = tmp11 * tmp21 - tmp12 * tmp22;
            st2[j][i] = tmp11 * tmp22 + tmp12 * tmp21;
        }
    }
    while (m--) {
        int l, r, x, y;
        scanf("%d%d%d%d", &l, &r, &x, &y);
        double nx = x, ny = y;
        r++;
        for (int i = 20; i >= 0; i--) {
            if (l + (1 << i) <= r) {
                double tmpx = st1[l][i] * nx - st2[l][i] * ny,
                       tmpy = st2[l][i] * nx + st1[l][i] * ny;
                nx = tmpx, ny = tmpy;
                l += 1 << i;
            }
        }
        printf("%f %f\n", nx, ny);
    }
    return 0;
}
/*
k1 -k2
k2 k1


*/