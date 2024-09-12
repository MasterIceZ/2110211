#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 100;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<pair<int, int>> st;
	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		st.emplace(l, r);
	}
	while(m--) {
		int x;
		cin >> x;
		auto it = st.lower_bound(make_pair(x, INF));
		if(it == st.begin()) {
			cout << "0";
		}
		else if(x <= (--it)->second) {
			cout << "1";
		}
		else {
			cout << "0";
		}
		cout << " ";
	}
	return 0;
}
