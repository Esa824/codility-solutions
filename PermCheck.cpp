#include <bits/stdc++.h>
using namespace std;
int PermCheck(vector<int> &A) {
  set<int> a;
  for (size_t i = 0; i < A.size(); i++) {
    a.insert(A[i]);
  }
  if (*max_element(a.begin(), a.end()) != A.size()) {
    return 0;
  }
  if (a.size() == A.size()) {
    return 1;
  }
  return 0;
}
