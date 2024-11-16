// Your code here

int rec(node* cur, KeyT& res, int& max_imbal) {
  if(cur == nullptr) {
    return 0;
  }
  int left_height = rec(cur->left, res, max_imbal);
  int right_height = rec(cur->right, res, max_imbal);
  int cur_diff = abs(left_height - right_height);
  if(max_imbal < cur_diff) {
    max_imbal = cur_diff;
    res = cur->data.first;
  }
  else if(max_imbal == cur_diff && mLess(cur->data.first, res)) {
    res = cur->data.first;
  }
  return 1 + std::max(left_height, right_height);
}

KeyT getValueOfMostImbalanceNode() {
  // Your code here
  KeyT res = mRoot->data.first;
  int max_imbal = 0;
  rec(mRoot, res, max_imbal);
  return res;
}
