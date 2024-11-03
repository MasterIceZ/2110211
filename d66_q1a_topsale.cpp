#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<int, int> mp;
set<pair<int, int>> st;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1, id; i<=n; ++i) {
    cin >> id;
    mp[id] = 0;
  }
  while(m--) {
    int opr;
    cin >> opr;
    if(opr == 1) {
      int a, b;
      cin >> a >> b;
      if(mp.find(a) == mp.end()) {
        continue;
      }
      st.erase(make_pair(mp[a], a));
      mp[a] += b;
      st.emplace(mp[a], a);
    }
    else {
      int k;
      cin >> k;
      auto it = st.lower_bound(make_pair(k, -1));
      if(it == st.begin()) {
        cout << "NONE\n";
      }
      else {
        cout << (--it)->second << "\n";
      }
    }
  }
  return 0;
}