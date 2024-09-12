#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

int get_second_min(stack<int> &s) {
	stack<int> t = s;
	const int INT_MX = 2147483647;
	int first_min = INT_MX, second_min = INT_MX;
	while(!t.empty()) {
		int cur = t.top(); t.pop();
		if(cur != first_min && cur < second_min) {
			second_min = cur;
		}
		if(second_min < first_min) {
			swap(first_min, second_min);
		}
	}
	return second_min;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	for (int last = 1;last < n;last+=1) {
		stack<int> s;
		//build s;
		bool distinct = false;
		for (int i = last;i >= 0;i--) {
			s.push(v[i]);
			if (v[i] != v[0]) distinct = true;
		}
		cout << "--use v[" << last << "] to v[0] --" << "\n";
		if (distinct) {
			//call get_second_min if we have at least 2 distinct value
			int answer = get_second_min(s);
			//print result and s
			cout << "result is " << answer << "\n";
			cout << "size of s is " << s.size() << "\n" << "member of s are ";
			while(s.size() > 0) {
				cout << s.top() << " ";
				s.pop();
			}
			cout << "\n";
		} else {
			cout << "skip because s has only one value\n\n\n";
		}
	}
	return 0;
}
