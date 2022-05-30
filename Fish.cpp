#include <bits/stdc++.h>
using namespace std;
int fish(vector<int> &A, vector<int> &B) {
  stack<int> s;
  int upstreams = 0;
  vector<int> downstreams;
  for (int i = 0; i < A.size(); i++) {
    if (B[i]) {
      s.push(A[i]);
    } else {
      while (!s.empty()) {
        if (A[i] > s.top()) {
          s.pop();
        } else {
          break;
        }
      }
    }
    if (s.empty()) {
      upstreams++;
    }
  }
  return upstreams + s.size();
}
