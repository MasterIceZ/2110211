#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, w;
  cin >> n >> w;
  vector<int> v(n);
  for(auto &x: v) {
    cin >> x;
  }
  multiset<int> ms;
  for(int i=0; i<=w; ++i) {
    ms.emplace(v[i]);
  }
  multiset<int>::iterator median_it = next(ms.begin(), w / 2);
  cout << *median_it << " ";
  for(int i=w+1; i<n; ++i) {
    ms.emplace(v[i]);
    if(v[i] < *median_it) {
      median_it--;
    }
    if(v[i - w - 1] <= *median_it) {
      median_it++;
    }
    cout << *median_it << " ";
    ms.erase(ms.lower_bound(v[i - w - 1]));
  }
  return 0;
}