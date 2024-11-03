#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  for(int i=0; i<std::min(k, (int) mSize); ++i) {
    int pos = (mFront + i) % mCap;
    res.push_back(mData[pos]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  mSize = to - from;
  mCap = mSize;
  mData = new T[mCap]();
  mFront = 0;
  for(size_t i=0; i<mSize; ++i) {
    mData[i] = *from;
    ++from;
  }
}

#endif
