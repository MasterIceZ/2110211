#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto &x: a) {
		cin >> x;
	}
	for(auto &x: b) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for(int i=0, j=0; i<(int) a.size() && j<(int) b.size(); ) {
		if(a[i] == b[j]) {
			cout << a[i] << " ";
			++i, ++j;
		}
		else if(a[i] < b[j]) {
			++i;
		}
		else {
			++j;
		}
	}
	cout << "\n";
	return 0;
}
