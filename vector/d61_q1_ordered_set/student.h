#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> st;
    for(auto x: A) {
      if(st.count(x)) {
        continue;
      }
      st.emplace(x);
      v.emplace_back(x);
    }
    for(auto x: B) {
      if(st.count(x)) {
        continue;
      }
      st.emplace(x);
      v.emplace_back(x);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> st;
    for(auto x: B) {
      st.emplace(x);
    }
    for(auto x: A) {
      if(st.count(x)) {
        v.emplace_back(x);
      }
    }
    return v;
}
