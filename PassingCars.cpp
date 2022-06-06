#include <bits/stdc++.h>
using namespace std;
int PassingCars(vector<int> &A) {
  long long check_zero = -1;
  long long result = 0;
  long long count = 0;
  for (size_t i = 0; i < A.size(); i++) {
    if (A[i] == 0) {
      check_zero = 1;
      count++;
      continue;
    }
    if (check_zero == 1) {
      result += count;
    }
  }
  if(result > 1000000000){
    return -1;
  }
  return result;
}
