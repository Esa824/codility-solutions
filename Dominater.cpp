#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;

    // Check if x is present at mid
    if (arr[m] == x)
      return m;

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

int Dominater(vector<int> &A) {
  map<int, int> big;
  for (size_t i = 0; i < A.size(); i++) {
    big[A[i]]++;
  }
  int occurs = 0;
  int key_of_biggest_number = 0;
  for (map<int, int>::iterator itr = big.begin(); itr != big.end(); itr++) {
    if (itr->second > occurs) {
      key_of_biggest_number = itr->first;
      occurs = itr->second;
    }
  }
  if (!occurs || occurs < A.size() / 2 + 1) {
    return -1;
  }
  int result = binarySearch(A, 0, A.size(), key_of_biggest_number);
  return result;
}
int main(){
  vector<int> input = {1,2,3,4,5};
  cout << Dominater(input);
}
