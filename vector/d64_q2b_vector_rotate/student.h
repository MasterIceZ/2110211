#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  CP::vector<T> helper;
  for(auto it=first; it!=last; ++it) {
    helper.push_back(*it);
  }
  CP::vector<T> rotate_helper;
  for(int i=0; i<(int) helper.size(); ++i) {
    rotate_helper.push_back(helper[(i - k + helper.size()) % helper.size()]);
  }
  int c = 0;
  for(auto it=first; it!=last; ++it) {
   *it = rotate_helper[++c];
  }
}

#endif
