#include <bits/stdc++.h>
using namespace std;
int MaxSliceSum(vector<int> &A) {
  int current_max = 0;
  int result = INT_MIN;
  for (int i = 0; i < A.size(); i++) {
    current_max = max(A[i], A[i] + current_max);
    if (current_max > result) {
      result = current_max;
    }
  }
  return result;
}
int main() {
  vector<int> A = {-2, 1};
  cout << MaxSliceSum(A);
}
