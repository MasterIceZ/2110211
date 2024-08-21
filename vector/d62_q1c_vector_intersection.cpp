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
	sort(b.begin(), b.end());
	map<int, bool> printed;
	for(int i=0, j=0; i<n && j<m;) {
		while(a[i] == b[j]) {
			if(!printed[a[i]]) {
				cout << a[i] << " ";
			}
			printed[a[i]] = true;
			++i, ++j;
		}
		if(a[i] < b[j]) {
			++i;
		}
		else {
			++j;
		}
	}
	cout << "\n";
	return 0;
}
