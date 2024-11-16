#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if(n == nullptr) {
    return -1;
  }
  int shallow_left = shallowest_leaf(n->left);
  int shallow_right = shallowest_leaf(n->right);
  if(shallow_left == -1 && shallow_right == -1) {
    return 0;
  }
  if(shallow_left == -1) {
    return shallow_right + 1;
  }
  if(shallow_right == -1) {
    return shallow_left + 1;
  }
  return std::min(shallow_right, shallow_left) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  return shallowest_leaf(mRoot);
}


#endif
