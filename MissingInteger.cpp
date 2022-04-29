#include <bits/stdc++.h>
using namespace std;
bool check_number(unordered_map<int, int> &map, int number) {
  bool result = false;
  if (map[number] == number) {
    return true;
  }
  return result;
}
int Passing_Cars(vector<int> &A) {
  unordered_map<int, int> map;
  int result = 1;
  for (size_t i = 0; i < A.size(); i++) {
    map[A[i]] = A[i];
    if (A[i] == result) {
      result++;
    }
  }
  result--;
  for (size_t i = 0; i < A.size(); i++) {
    result++;
    if (check_number(map, result) == false) {
      return result;
    }
  }
  return A.size() + 1;
}
