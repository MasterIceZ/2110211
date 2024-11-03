#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  if(mSize == 0) {
    return -1;
  }
  int lg = 0;
  size_t s = mSize;
  while(s / 2 != 0) {
    s /= 2;
    lg++;
  }
  return lg;
}

#endif

