#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
  T data = mData[idx];
  while(idx > 0) {
    size_t next_idx = (idx - 1) / 4;
    if(mLess(data, mData[next_idx])) {
      break;
    }
    mData[idx] = mData[next_idx];
    idx = next_idx;
  }
  mData[idx] = data;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
  T data = mData[idx];
  while((idx * 4) + 1 < mSize) {
    // BRUH
    if(mLess(mData[next_idx], data)) {
      break;
    }
    mData[idx] = mData[next_idx];
    idx = next_idx;
  }
  mData[idx] = data;
}

#endif

