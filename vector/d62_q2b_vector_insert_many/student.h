#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  sort(data.begin(), data.end());
  int new_size = data.size() + mSize;
  ensureCapacity(new_size);
  int new_index=new_size-1, data_ptr=data.size()-1;
  if(data[data_ptr].first == mSize) {
    mData[new_index] = data[data_ptr].second;
    data_ptr--;
    new_index--;
  }
  for(int data_index=mSize-1; data_index>=0; --data_index) {
    if(data_ptr >= 0 && data[data_ptr].first - 1 == data_index) {
      mData[new_index] = data[data_ptr].second;
      data_ptr--;
      new_index--;
    }
    mData[new_index] = mData[data_index];
    new_index--;
  }
  if(data[data_ptr].first == 0) {
    mData[new_index] = data[data_ptr].second;
    data_ptr--;
    new_index--;
  }
  mSize = new_size;
}

#endif
