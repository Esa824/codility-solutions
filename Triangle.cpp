#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int Tringle(vector<int> &A) {
  vector<long> arr(A.begin(), A.end());
  sort(arr.begin(), arr.end());
  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] + arr[i + 1] > arr[i + 2] && arr[i + 1] + arr[i + 2] > arr[i] &&
        arr[i + 2] + arr[i] > arr[i + 1]) {
      return 1;
    }
    if (i + 3 >= arr.size()) {
      break;
    }
  }
  return 0;
}
