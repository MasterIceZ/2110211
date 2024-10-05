#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
  CP::stack<T> helper;
  for(int i=0; i<a; ++i) {
    helper.push(top());
    pop();
  }
  for(int i=a; i<=b; ++i) {
    helper.push(top());
    helper.push(top());
    pop();
  }
  while(!helper.empty()) {
    push(helper.top());
    helper.pop();
  }
}

#endif