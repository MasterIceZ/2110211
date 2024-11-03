#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int mem[MxN], sum[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, start;
  cin >> n >> m >> start;
  for(int i=1, a, b; i<=n; ++i) {
    cin >> a >> b;
    mem[a] = b;
  }
  mem[0] = start;
  for(int i=1; i<MxN; ++i) {
    if(mem[i] == 0) {
      mem[i] = start;
    }
    else {
      start = mem[i];
    }
    mem[i] += mem[i - 1];
  }
  while(m--) {
    int p, x;
    cin >> p >> x;
    if(p <= mem[x]) {
      cout << lower_bound(mem, mem + MxN, p) - mem;
    }
    else {
      cout << lower_bound(mem, mem + MxN, mem[x] + p) - mem;
    }
    cout << " ";
  }
  return 0;
}