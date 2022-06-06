#include <bits/stdc++.h>
using namespace std;
int plus_from(vector<int> &A, int n) {
  int result = 0;
  for (size_t i = n; i < A.size(); i++) {
    result += A[i];
  }
  return result;
}
int TapEquilibrium(vector<int> &A) {
  if (equal(A.begin() + 1, A.end(), A.begin())) {
    return 0;
  }
  int spot = 1;
  int plus = A[0];
  int result = 0;
  int check = 0;
  int  b = plus_from(A,0);
  for (size_t i = 1; i < A.size(); i++) {
    b -= A[spot - 1];
    int a = b - plus;
    if(a < 0){
      a *= -1;
    }
    if (a == 0) {
      return 0;
    }
    if (a < result || check == 0) {
      result = a;
      check = 1;
    }
    spot++;
    plus += A[i];
  }
  return result;
}
