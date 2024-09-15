#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

#define SQRT_SZ 2000

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  int idx  = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  if(idx != 0) {
    index -= aux[idx - 1];
  }
  if(idx == (int) mData.size()) {
    mData.emplace_back(value);
  }
  else {
    mData[idx].insert(mData[idx].begin() + index, value.begin(), value.end());
    if((int) mData[idx].size() > SQRT_SZ) {
      mData.insert(mData.begin() + idx + 1, std::vector<T> (mData[idx].begin() + SQRT_SZ, mData[idx].end()));
      mData[idx].resize(SQRT_SZ);
    }
  }
  aux.resize((int) mData.size());
  for(; idx < (int) mData.size(); ++idx) {
    if(idx == 0) {
      aux[idx] = (int) mData[idx].size();
    }
    else {
      aux[idx] = (int) mData[idx].size() + aux[idx - 1];
    }
  }
  mSize = mCap = aux.back();
}

#endif