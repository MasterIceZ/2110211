#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxM = 100010;

queue<ll> q[3];
ll p[MxM];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> p[i];
	}
	vector<ll> tot = {0ll};
	for(int i=1, opr, shop, money; i<=n; ++i) {
		cin >> opr;
		if(opr == 1) {
			cin >> shop >> money;
			q[shop].emplace((ll) money);
		}
		else {
			if(q[2].empty() || (!q[1].empty() && !q[2].empty() && q[1].front() <= q[2].front())) {
				tot.emplace_back(q[1].front() + tot.back());
				q[1].pop();
			}
			else {
				tot.emplace_back(q[2].front() + tot.back());
				q[2].pop();
			}
		}
	}
	for(int i=1; i<=m; ++i) {
		auto it = lower_bound(tot.begin(), tot.end(), p[i]);
		cout << (it == tot.end() ? -1: (it - tot.begin())) << " ";
	}
	return 0;
}
