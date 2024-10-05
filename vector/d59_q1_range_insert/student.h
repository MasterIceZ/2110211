#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int insertion_size = last - first;
  ensureCapacity(mSize + insertion_size);
  int insertion_index = position - begin();
  for(int i=mSize-1; i>=insertion_index; --i) {
    mData[i + insertion_size] = mData[i];
  }
  for(int i=0; i<insertion_size; ++i) {
    mData[insertion_index + i] = *(first + i);
  }
  mSize += insertion_size;
}

#endif
