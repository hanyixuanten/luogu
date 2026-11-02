#include <bits/stdc++.h>
using namespace std;
set<int> s;
map<int, int> rev;
int n;
int tmp;
int main(void) {
	scanf("%d%d", &n, &tmp), s.insert(tmp), rev[tmp] = 1;
	for(int i = 2; i <= n; i++) {
		scanf("%d", &tmp), s.insert(tmp), rev[tmp] = i;
		auto lb = s.lower_bound(tmp), ub = s.upper_bound(tmp);
		int minval = INT_MAX, ind = 0;
		if(lb != s.begin()) {
			--lb;
			if(abs(tmp - *lb) < minval)
				minval = abs(tmp - *lb), ind = rev[*lb];
		}
		if(ub != s.end())
			if(abs(tmp - *ub) < minval)
				minval = abs(tmp - *ub), ind = rev[*ub];
		printf("%d %d\n", minval, ind);
	}
	
	return 0;
}
