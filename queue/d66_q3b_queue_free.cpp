#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int q, opr;
  ll cur_cap = 1ll, cur_size = 0ll, n;
  cin >> q;
  while(q--) {
    cin >> opr >> n;
    if(opr == 0) {
      cur_size += n;
      while(cur_cap < cur_size) {
        cur_cap *= 2;
      }
    }
    else {
      cur_size -= n;
    }
  }
  cout << cur_cap - cur_size << "\n";
  return 0;
}