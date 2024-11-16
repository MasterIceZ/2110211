#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN];
map<int, priority_queue<int>> mp;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q, x, remains = 0;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    mp[a[i]].emplace(i);
    remains += a[i];
  }
  while(q--) {
    cin >> x;
    if(x > remains) {
      cout << "-1\n";
      continue;
    }
    remains -= x;
    vector<pair<int, int>> v;
    while(x > 0) {
      auto it = mp.lower_bound(x);
      if(it == mp.end()) {
        --it;
      }
      int deleting = min(x, it->first);
      int flr = it->second.top();
      v.emplace_back(flr, deleting);
      it->second.pop();
      int cur_remains = it->first - deleting;
      if(cur_remains > 0) {
        mp[cur_remains].emplace(flr);
      }
      if(it->second.empty()) {
        mp.erase(it);
      }
      x -= deleting;
    }
    sort(v.begin(), v.end());
    for(auto [r, p]: v) {
      cout << r << " " << p << " ";
    }
    cout << "\n";
  }
  return 0;
}