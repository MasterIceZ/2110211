#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
string s;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> s;
		mp[s]++;
	}
	for(auto [s, cnt]: mp) {
		if(cnt == 1) {
			continue;
		}
		cout << s << " " << cnt << "\n";
	}
	return 0;
}
