#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

void rec(int a, vector<int> &v) {
  if(a >= n) {
    return ;
  }
  v.emplace_back(a);
  rec(a * 2 + 1, v);
  rec(a * 2 + 2, v);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int a;
  cin >> n >> a;
  vector<int> v;
  rec(a, v);
  sort(v.begin(), v.end());
  cout << v.size() << "\n";
  for(auto x: v) {
    cout << x << " ";
  }
  return 0;
}