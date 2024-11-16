#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

// // you can modify and use this function
// template <typename KeyT,
//           typename MappedT,
//           typename CompareT>
// void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,size_t level,size_t tmp,std::vector<KeyT> &v) {
//   //you MAY need to use this function

// }

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT,MappedT,CompareT>::at_level(size_t level) {
  //write your code here
  std::vector<KeyT> res;
  std::queue<node*> q;
  q.push(mRoot);
  for(int l=0; l<(int) level; ++l) {
    int level_size = (int) q.size();
    for(int i=0; i<level_size; ++i) {
      node* u = q.front(); q.pop();
      if(u->left != nullptr) {
        q.push(u->left);
      }
      if(u->right != nullptr) {
        q.push(u->right);
      }
    }
  }
  while(!q.empty()) {
    res.push_back(q.front()->data.first);
    q.pop();
  }
  reverse(res.begin(), res.end());
  return res;
}


#endif
