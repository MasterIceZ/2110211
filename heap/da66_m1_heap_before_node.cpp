#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

void rec(int a, set<int>& st) {
  if(a >= n) {
    return ;
  }
  st.erase(a);
  rec(a * 2 + 1, st);
  rec(a * 2 + 2, st);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int a;
  cin >> n >> a;
  set<int> st;
  for(int i=0; i<n; ++i) {
    st.emplace(i);
  }
  rec(a, st);
  cout << st.size() << "\n";
  for(auto x: st) {
    cout << x << " ";
  }
  return 0;
}