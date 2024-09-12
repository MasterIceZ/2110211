#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void list_erase(vector<int> &v, vector<int> &pos) {
	//write your code here
	vector<int> t = pos, s;
	const int INF = (int) 1e9;
	t.emplace_back(INF);
	sort(t.begin(), t.end());
	for(int i=0, it = 0; i<(int) v.size(); ++i) {
		if(i == t[it]) {
			++it;
			continue;
		}
		s.emplace_back(v[i]);
	}
	v = s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> v(n), pos(m);
	for (int i = 0;i < n;i++) cin >> v[i];
	for (int i = 0;i < m;i++) cin >> pos[i];
	list_erase(v,pos);
	cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
	for (auto &x : v) cout << x << " ";
	cout << endl;
}
