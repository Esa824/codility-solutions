#include <bits/stdc++.h>
using namespace std;
int OddOcurrencesinArray(vector<int> &A) {
  sort(A.begin(), A.end());
  int i, j, count = 0;
  for (i = 0; i < A.size(); i++) {
    for (j = i + 1; j < A.size(); j++) {
      if (A[i] == A[j])
        count++;
      else
        break;
    }
    if (count % 2 == 0)
      return A[i];
    else {
      count = 0;
      i = j - 1;
    }
  }
  return 0;
}
