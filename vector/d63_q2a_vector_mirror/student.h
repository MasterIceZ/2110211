#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
	size_t n = mSize;
  size_t cur_pos = mSize;

  for(int i=n-1; i>=0; --i) {
    ensureCapacity(mSize + 1);
    mData[cur_pos] = mData[i];
    cur_pos++, mSize++;
  }
}

#endif
