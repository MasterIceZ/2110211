#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, int> p;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		ll a, b;
		cin >> a >> b;
		p[b] = a;
	}
	while(q--) {
		ll a, b;
		cin >> a >> b;
		ll prnt_a = p[p[a]], prnt_b = p[p[b]];
		if(prnt_a == 0 || prnt_b == 0 || a == b || prnt_a != prnt_b) {
			cout << "NO" << "\n";
		}
		else if(prnt_a == prnt_b) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}
