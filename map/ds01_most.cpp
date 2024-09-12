#include <iostream>
#include <map>
#include <string>

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
	int max_cnt = 0;
	string answer = "";
	for(auto [s, cnt]: mp) {
		if(cnt >= max_cnt) {
			answer = s;
			max_cnt = cnt;
		}
	}
	cout << answer << " " << max_cnt << "\n";
	return 0;
}
