#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  CP::list<T> res;
  if(pos == mSize) {
    return res;
  }
  res.mSize = mSize - pos;
  mSize = pos;

  node* ptr = it.ptr;
  node* last = mHeader->prev;
  
  ptr->prev->next = mHeader;
  mHeader->prev = ptr->prev;

  res.mHeader->next = ptr;
  ptr->prev = res.mHeader;

  res.mHeader->prev = last;
  last->next = res.mHeader;

  return res;
}

#endif
