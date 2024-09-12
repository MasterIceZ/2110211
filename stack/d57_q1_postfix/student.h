#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
	stack<int> st;
	for(auto [opr, val]: v) {
		if(opr == 1) {
			st.emplace(val);
		}
		else {
			int rhs = st.top(); st.pop();
			int lhs = st.top(); st.pop();

			if(val == 0) {
				st.emplace(lhs + rhs);
			}
			else if(val == 1) {
				st.emplace(lhs - rhs);
			}
			else if(val == 2) {
				st.emplace(lhs * rhs);
			}
			else {
				st.emplace(lhs / rhs);
			}
		}
	}
	return st.top();
}

#endif
