#include <bits/stdc++.h>

using namespace std;

set<int> st;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1, x; i<=n; ++i) {
		cin >> x;
		st.emplace(x);
	}
	while(m--) {
		int x;
		cin >> x;
		cout << distance(st.lower_bound(x - k), st.upper_bound(x + k)) << " ";
	}
	return 0;
}
