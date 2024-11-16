#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here

  for (node* it = mHeader->next; it != mHeader; ) {
    if(it->data != value) {
      it = it->next;
      continue;
    }
    node* helper = it->next;
    it->prev->next = it->next;
    it->next->prev = it->prev;
    delete it;
    mSize--;
    it = helper;
  }
}

#endif
