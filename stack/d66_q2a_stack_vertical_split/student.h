#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  for(int i=1; i<=k; ++i) {
    output.push_back(std::stack<T>());
  }
  int base = mSize / k;
  int remains = mSize % k;
  int t = 0;
  for(int i=mSize-1; i>=0; ) {
    int to_add = base + (remains >= 1);
    for(int j=i-to_add+1, c=to_add; c > 0; --c, ++j) {
      output[t].push(mData[j]);
    }
    remains--;
    t++;
    i -= to_add;
  }
}

#endif
