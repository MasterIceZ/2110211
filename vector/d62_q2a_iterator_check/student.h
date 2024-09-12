#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  size_t pos = it - &mData[0];
  return (0 <= pos && pos < mSize);
}

#endif
