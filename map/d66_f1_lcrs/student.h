// You may include library here
#include <algorithm>

int depth(node *n) {
  if(n == nullptr) {
    return -1;
  }
  return std::max(depth(n->left_child) + 1, depth(n->right_sibling));
}