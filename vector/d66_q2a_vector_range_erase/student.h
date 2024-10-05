#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  CP::vector<int> sum(mSize);
  for(auto [it_b, it_e]: ranges) {
    sum[it_b - begin()]++;
    if(it_e - begin() < mSize) {
      sum[it_e - begin()]--;
    }
  }
  int it=0, cur_sum=0;
  for(int i=0; i<mSize; ++i) {
    cur_sum += sum[i];
    if(cur_sum == 0) {
      mData[it] = mData[i];
      it++;
    }
  }
  mSize = it;
}

#endif
