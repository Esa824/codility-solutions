#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;

    // Check if x is present at mid
    if (arr[m] == x) {
      return m;
    }

    // If x greater, ignore left half
    if (arr[m] < x)
      l = m + 1;

    // If x is smaller, ignore right half
    else
      r = m - 1;
  }

  // if we reach here, then element was
  // not present
  return -1;
}

int MaxDoubleSliceSum(vector<int> &A) {
  vector<int> frontKadane(A.size());
  vector<int> backKadane(A.size());
  vector<int> prefix;
  int result = 0;
  // Loop to calculate the
  // maximum subarray sum till ith index
  for (int i = 1; i < A.size() - 1; i++) {
    frontKadane[i] = max(frontKadane[i - 1] + A[i], 0);
  }
  // Loop to calculate the
  // maximum subarray sum till ith index
  for (int i = A.size() - 2; i >= 0; i--) {
    backKadane[i] = max(backKadane[i + 1] + A[i], 0);
  }
  for (int i = 1; i < A.size() - 1; i++) {
    result = max(result, frontKadane[i - 1] + backKadane[i + 1]);
  }
  // Return the maximum
  // non-overlapping subarray sum
  return result;
}
