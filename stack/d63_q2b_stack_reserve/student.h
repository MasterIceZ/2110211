#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    size_t remain = mCap - mSize;
    size_t other_remain = other.mCap - other.mSize;
    if(remain < other_remain) {
      return -1;
    }
    if(remain > other_remain) {
      return 1; 
    }
    return 0;
}

#endif
