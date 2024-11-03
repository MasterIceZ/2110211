#include <iostream>
#include <vector>

using namespace std;

int _relation(long long S, long long a, long long b) {
  if(a == b) {
    return 4;
  }
  if(a > b) {
    swap(a, b);
  }
  for(int i=1; i<=S; ++i) {
    if(b == a * S + i) {
      return 1;
    }
  }
  int bb = b;
  while(a < bb) {
    bb = (bb - 1) / S;
  }
  if(a == bb) {
    return 2;
  }
  int hei_a = 0, hei_b = 0;
  while(a > 0) {
    hei_a++;
    a = (a - 1) / S;
  }
  while(b > 0) {
    hei_b++;
    b = (b - 1) / S;
  }
  return hei_a == hei_b ? 4: 3;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  long long S,a,b;
  cin >> n;
  while (n--) {
    cin >> S >> a >> b;
    cout << _relation(S,a,b) << " ";
  }
  cout << endl;
}