#include<bits/stdc++.h>
using namespace std;
long long x, y;
int main() {
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", (long long) ceil((y - x) / (long double)2.0));
}