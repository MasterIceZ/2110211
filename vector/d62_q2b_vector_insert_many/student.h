#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  std::sort(data.begin(), data.end());
  size_t newSize = data.size() + mSize;
  ensureCapacity(newSize);
  size_t cur_it = newSize - 1;
  for(size_t i=mSize, j=data.size()-1; i>=0; --i) {
    if(i != mSize) {
      mData[cur_it] = mData[i];
      cur_it--;
    }
    if(data[j].first == i) {
      mData[cur_it] = data[j].second;
      cur_it--, j--;
    }
  }
  mSize = newSize;
}

#endif
