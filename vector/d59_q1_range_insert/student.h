#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int insert_size = last - first;
  int new_size = mSize + insert_size;
  int position_index = position - begin();
  // std::cerr << "X: " << position_index << "\n";
  ensureCapacity(new_size);
  for(int i=mSize-1; i>=position_index; --i) {
    mData[i + insert_size] = mData[i];
    // std::cerr << "D: " << i + insert_size << " " << i << "\n";
  }
  int index = position_index;
  for(auto it=first; it!=last; ++it) {
    mData[index] = *it;
    index++;
  }
  mSize = new_size;
}

#endif
