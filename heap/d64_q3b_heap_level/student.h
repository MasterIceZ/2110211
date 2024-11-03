#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  std::vector<T> r;
  size_t cur = 0;
  for(int i=0; i<k; ++i) {
    cur 
  }
  for(int i=0; i<(1 << k); ++i) {
    r.emplace_back(mData[i]);
  }
  return r;
}

#endif

