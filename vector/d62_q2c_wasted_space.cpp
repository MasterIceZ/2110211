#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int lg = 31 - __builtin_clz(n - 1) + 1;
	cout << ((1 << lg) - n) << "\n";
	return 0;
}
