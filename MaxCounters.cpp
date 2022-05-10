#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void print_time() {
  time_t the_time = time(NULL);
  printf("%s", ctime(&the_time));
}
vector<int> MaxCounters(int N, vector<int> &A) {
  vector<int> result(N);
  int fill = 0;
  int greatest_number = 0;
  for (size_t i = 0; i < A.size(); i++) {
    if (A[i] <= N) {
      int counter = max(result[A[i] - 1], fill);
      result[A[i] - 1] = counter;
      result[A[i] - 1]++;
      if (greatest_number < result[A[i] - 1]) {
        greatest_number = result[A[i] - 1];
      }
    } else {
      fill = greatest_number;
    }
  }
  for (size_t i = 0; i < result.size(); i++) {
    result[i] = max(result[i], fill);
  }
  return result;
}

