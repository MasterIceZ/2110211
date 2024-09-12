#include <iostream>
#include <vector>
#include <queue>

using namespace std;

size_t qcount(queue<int> q, int k) {
	size_t answer = (size_t) 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		answer += (size_t) (cur == k ? 1: 0);
	}
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	cout << qcount(q,k) << endl;
}
