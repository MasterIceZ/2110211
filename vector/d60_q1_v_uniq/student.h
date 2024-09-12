#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure

#include <set>

template <typename T>
void CP::vector<T>::uniq() {
	//do someting here
	std::set<T> st;
	size_t it = 0;
	for(int i=0; i<(int) mSize; ++i) {
		if(st.count(mData[i])) {
			continue;
		}
		mData[it++] = mData[i];
		st.emplace(mData[i]);
	}
	mSize = it;
}

#endif
