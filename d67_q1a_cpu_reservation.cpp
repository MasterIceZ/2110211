#include <bits/stdc++.h>

using namespace std;

set<int> st;
map<int, int> mp;

bool check(int al, int ar, int bl, int br) {
	if(al < bl && ar < bl) {
		return true;
	}
	if(al > br && ar > br) {
		return true;
	}
	return false;
}

void add_seg(int l, int r) {
	st.emplace(l);
	st.emplace(r);
	mp[l] = r;
	mp[r] = l;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		auto it = st.lower_bound(l);
		if(it == st.end()) {
			cout << i << " ";
			add_seg(l, r);
			continue;
		}
		pair<int, int> have = minmax(*it, mp[*it]);
		if(!check(l, r, have.first, have.second)) {
			continue;
		}
		add_seg(l, r);
		cout << i << " ";
	}
	return 0;
}
