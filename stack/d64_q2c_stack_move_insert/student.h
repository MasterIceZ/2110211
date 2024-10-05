#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  CP::stack<T> helper;
  while(k-- && !empty()) {
    helper.push(top());
    pop();
  }
  while(m-- && !s2.empty()) {
    helper.push(s2.top());
    s2.pop();
  }
  while(!helper.empty()) {
    push(helper.top());
    helper.pop();
  }
}
#endif
