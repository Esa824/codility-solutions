#include <iostream>
#include <vector>
using namespace std;
vector<int> CyclicRotaion(vector<int> &A, int K) {
  if (A.size() == 0 || K < 0 || A.size() == 1) {
    return A;
  }
  int KK = K;
  int g = K;
  g = g - A.size();
  K = K > A.size() ? g : K;
  if (K > A.size()) {
    K = KK;
    int m = K;
    int mm = K;
    int ge = 0;
    while (m != 0) {
      m %= 10;
      ge = ge < m || ge == 0 ? m : ge;
      mm /= 10;
      m = mm;
    }
    ge = A.size() - ge;
    K = K > A.size() ? ge + 1 : K;
  }
  vector<int> result;
  for (size_t i = A.size() - K; i < A.size(); i++) {
    result.push_back(A[i]);
  }
  for (size_t i = 0; i < A.size() - K; i++) {
    result.push_back(A[i]);
  }
  return result;
}
