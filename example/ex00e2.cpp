#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;
const int LG = 8;

int sparse_table[LG][LG][MxN][MxN];
int lg[MxN];

void init(vector<vector<int>> arr){
	int n = arr.size();
	int m = arr[0].size();
	for(int state=2; state<MxN; ++state){
		lg[state] = lg[state >> 1] + 1;
	}
	memset(sparse_table, -0x3f, sizeof sparse_table);
	// base case
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			sparse_table[0][0][i][j] = arr[i][j];
		}
	}
	// precompute
	for(int state_i=0; state_i<LG; ++state_i){
		for(int state_j=0; state_j<LG; ++state_j){
			if(state_i + state_j == 0){
				continue;
			}
			for(int i=0; i+(1 << state_i)<=n; ++i){
				for(int j=0; j+(1 << state_j)<=m; ++j){
					if(state_i == 0){
						sparse_table[state_i][state_j][i][j] = max(sparse_table[state_i][state_j - 1][i][j], sparse_table[state_i][state_j - 1][i][j + (1 << (state_j - 1))]);
					}
					else{
						sparse_table[state_i][state_j][i][j] = max(sparse_table[state_i - 1][state_j][i][j], sparse_table[state_i - 1][state_j][i + (1 << (state_i - 1))][j]);
					}
				}
			}
		}
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> arr(n, vector<int> (m));
	for(auto &v: arr) {
		for(auto &x: v) {
			cin >> x;
		}
	}
	init(arr);
	while(q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(c < a || b > d) {
			cout << "INVALID\n";
		}
		else if(c < 1 || a > n || d < 1 || b > m) {
			cout << "OUTSIDE\n";
		}
		else {
			a--, b--;
			a = max(0, a), b = max(0, b);
			c = min(n, c), d = min(m, d);
			int state_i = lg[c - a], state_j = lg[d - b];
			int A = sparse_table[state_i][state_j][a][b];
			int B = sparse_table[state_i][state_j][c - (1 << state_i)][b];
			int C = sparse_table[state_i][state_j][a][d - (1 << state_j)];
			int D = sparse_table[state_i][state_j][c - (1 << state_i)][d - (1 << state_j)];
			cout << max({A, B, C, D}) << "\n";
		}
	}
	return 0;
}
