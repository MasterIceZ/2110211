#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
  std::vector<std::vector<T>> r;
  for(int i=1; i<=k; ++i) {
    r.emplace_back(std::vector<T> ());
  }
  int base = mSize / k;
  int remains = mSize % k;
  int it = 0;
  for(int i=mSize-1; i>=0; --i) {
    r[it].emplace_back(mData[i]);
    it = (it + 1) % k;
  }
  for(int i=0; i<k; ++i) {
    std::reverse(r[i].begin(), r[i].end());
  }
  return r;
}

#endif

