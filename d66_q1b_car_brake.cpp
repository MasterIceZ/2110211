#include <bits/stdc++.h>

using namespace std;

const int MxN = 300030;

struct query_t {
	int t;
	bool mode;
	int v;
	bool operator < (const query_t &o) const {
		if(t != o.t) {
			return t < o.t;
		}
		return mode < o.mode;
	}
	query_t(int _t, bool _mode, int _v):
		t(_t), mode(_mode), v(_v) {}
};

vector<query_t> queries;
vector<pair<int, int>> type_2;
int answer[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1, t, d; i<=n; ++i) {
		cin >> t >> d;
		queries.emplace_back(t, false, d);	
	}
	for(int i=1, a, q; i<=m; ++i) {
		cin >> a >> q;
		if(a == 1) {
			queries.emplace_back(q, true, i);
		}
		if(a == 2) {
			type_2.emplace_back(-q, i);
		}
	}
	queries.emplace_back(0, false, 0);
	sort(queries.begin(), queries.end());
	sort(type_2.begin(), type_2.end());
	int cur_speed = k, it = 0;
	for(auto query: queries) {
		if(query.mode == false) {
			cur_speed = max(0, cur_speed - query.v);	
		}
		else {
			answer[query.v] = cur_speed;
		}
		while(it < (int) type_2.size() && cur_speed < -type_2[it].first) {
			answer[type_2[it].second] = query.t;
			it++;
		}
	}
	for(int i=1; i<=m; ++i) {
		cout << answer[i] << "\n";
	}
	return 0;
}
