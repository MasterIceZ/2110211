#include <iostream>
#include <vector>

using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
	int pos = it - v.begin();

	auto max = [&](int a, int b) {
		return a > b ? a: b;
	};
	auto min = [&](int a, int b) {
		return a < b ? a: b;
	};

	int l = max(0, pos - k);
	int r = min((int) v.size(), pos + k + 1);
	v.erase(v.begin() + l, v.begin() + r);
	return v;
}

int main() {
	int n,j,k;
	cin >> n >> j >> k;
	vector<string> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	cout << "Result after punch" << endl;
	vector<string> result = punch(v, v.begin() + j, k);
	for (auto &x : result) {
		cout << x << endl;
	}
}
