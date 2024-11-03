#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>
#include <vector>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
  std::map<T, size_t> cnt;
  for(int i=0; i<mSize; ++i) {
    int pos = (i + mFront) % mCap;
    cnt[mData[pos]]++;
  }
  std::vector<std::pair<T, size_t>> res;
  for(auto x: k) {
    res.emplace_back(x, cnt[x]);
  }
  return res;
}

#endif
