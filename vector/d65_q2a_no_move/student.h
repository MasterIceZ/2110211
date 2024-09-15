#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  int ub = std::upper_bound(aux.begin(), aux.end(), idx) - aux.begin();
  if(ub != 0) {
    idx -= aux[ub - 1];
  }
  return mData[ub - 1][idx];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  aux.emplace_back(mSize);
}

#endif
