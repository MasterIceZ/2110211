#include <bits/stdc++.h>

using namespace std;

const int MxN = 10010;
const int MxA = 2000020;

int a[MxN], cnt[MxA];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	while(q--) {
		int x;
		cin >> x;
		bool printed = false;
		for(int i=1; i<=n; ++i) {
			int expect = x - a[i];
			if(expect < 0) {
				break;
			}
			int status = (expect == a[i]);
			if(cnt[expect] - status > 0) {
				cout << "YES";
				printed = true;
				break;
			}
		}
		if(!printed) {
			cout << "NO";
		}
		cout << "\n";
	}
	return 0;
}
