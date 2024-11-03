#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  int it = pos;
  CP::stack<T> helper;
  for(int cnt=0; !empty()&&cnt<pos; ++cnt) {
    helper.push(top());
    pop();
  }
  push(value);
  while(!helper.empty()) {
    push(helper.top());
    helper.pop();
  }
}

#endif
