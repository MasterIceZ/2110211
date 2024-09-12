#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  size_t it = 0;
  for(size_t i=0, cur=0; i<mSize; ++i) {
    if(cur < pos.size() && i == pos[cur]) {
      cur++;
      continue;
    }
    mData[it++] = mData[i];
  }
  mSize = it;
}

#endif
