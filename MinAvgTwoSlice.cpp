#include <bits/stdc++.h>
#include <limits>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
  float avg = 0;
  int min_index = 0;
  int position = 0;

  // My vector of sums starting from th beggining to the end
  vector<float> sums;

  int prefix = 0;
  for (int i = 0; i < A.size(); i += 1) {
    prefix += A[i];
    sums.push_back(prefix);
  }
  float min_avg = numeric_limits<float>::max();
  for (int i = 1; i < A.size(); i++) {
    // Getting the average
    avg = (sums[i] - sums[position] + A[position]) / (i - position + 1);

    // Comparing gotten average with the smallest one
    if (avg < min_avg) {
      min_avg = avg;
      min_index = position;
    }

    // If the value itself it less then the average
    if (A[i] < min_avg) {
      position = i;
    }
  }
  return min_index;
}
