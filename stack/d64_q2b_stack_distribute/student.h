#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  int base = mSize / k;
  int remains = mSize % k;
  std::vector<std::vector<T>> r;
  int it = mSize - 1;
  for(int i=0; i<k; ++i) {
    int to_add = base + (remains > 0);
    r.emplace_back(std::vector<T> ());
    while(to_add--) {
      r.back().emplace_back(mData[it]);
      --it;
    }
    remains--;
  }
  return r;
}
#endif
