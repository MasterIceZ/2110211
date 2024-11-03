#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  std::vector<T> a, b;
  for(int i=0; i<(int) mSize; ++i) {
    a.push_back(mData[i]);
  }
  for(int i=0; i<(int) other.mSize; ++i) {
    b.push_back(other.mData[i]);
  }
  std::sort(a.begin(), a.end(), mLess);
  std::sort(b.begin(), b.end(), other.mLess);
  if(a.size() != b.size()) {
    return false;
  }
  for(int i=0; i<(int) mSize; ++i) {
    if(a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

#endif
