#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 50050;

struct state_t {
  int val, idx, t;
  bool operator < (const state_t& o) const {
    if(val != o.val) {
      return val > o.val;
    }
    if(idx != o.idx) {
      return idx > o.idx;
    }
    return t > o.t;
  }
  state_t(int _val, int _idx, int _t):
    val(_val), idx(_idx), t(_t) {}
};

priority_queue<state_t> pq;
int n, m, p[MxN], t[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1; i<=m; ++i) {
    p[i] = 1;
    pq.emplace(p[i], i, 0);
  }
  vector<pair<int, int>> a(n);
  for(int i=0; i<n; ++i) {
    cin >> a[i].second;
  }
  for(int i=0; i<n; ++i) {
    cin >> a[i].first;
    a[i].first += 1;
  }
  int timer = 0;
  for(auto [kind, pw]: a) {
    if(p[kind] < pw) {
      p[kind] = pw;
      t[kind] = ++timer;
      pq.emplace(p[kind], kind, t[kind]);
    }
    while(!pq.empty() && t[pq.top().idx] != pq.top().t) {
      pq.pop();
    }
    cout << pq.top().val << " ";
  }
  return 0;
}