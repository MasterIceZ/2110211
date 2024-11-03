#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  std::vector<T> t;
  for(size_t i=0; i<pos.size(); ++i) {
    if(pos[i] >= mSize) continue;
    t.emplace_back(mData[(pos[i] + mFront) % mCap]);
  }
  return *std::min_element(t.begin(), t.end(), comp);
}

#endif
