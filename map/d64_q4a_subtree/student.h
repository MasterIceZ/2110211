#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  // subtree size
  if(n == nullptr) {
    return 0;
  }
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if(mRoot == nullptr) {
    return std::pair<KeyT,MappedT>();
  }
  size_t left_size = process(mRoot->left);
  size_t right_size = process(mRoot->right);
  left.mRoot = mRoot->left;
  left.mSize = left_size;
  right.mRoot = mRoot->right;
  right.mSize = right_size;
  mRoot->left = nullptr;
  mRoot->right = nullptr;
  mSize = 1;
  return mRoot->data;
}

#endif

