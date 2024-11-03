#include <bits/stdc++.h>

using namespace std;

template<typename T>
class deque_stack {
protected:
	stack<T> a, b;
public:
	void push_top(T v) {
		a.emplace(v);
	}
	void push_bot(T v) {
		b.emplace(v);
	}
	void balance(stack<T> &l, stack<T> &r) {
		// move from l to r
		int mid_sz = (l.size() / 2) + (l.size() % 2 == 1);
		stack<T> helper;
		while(mid_sz--) {
			r.emplace(l.top());
			l.pop();
		}
	}
	void pop_top() {
		if(a.empty()) {
			balance(b, a);
		}
		a.pop();
	}
	void pop_bot() {
		if(b.empty()) {
			balance(a, b);
		}
		b.pop();
	}
	T top() {
		if(a.empty()) {
			balance(b, a);
		}
		return a.top();
	}
	T bot() {
		if(b.empty()) {
			balance(a, b);
		}
		return b.top();
	}	
	bool empty() {
		return a.empty() && b.empty();
	}
};

int main() {
	deque<int> st;
	st.push_front(1); st.push_front(3);
	cout << st.back() << "\n";
	cout << st.front() << "\n";
	return 0;
}
