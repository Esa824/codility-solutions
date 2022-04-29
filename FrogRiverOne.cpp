#include <bits/stdc++.h>
using namespace std;
bool check_map(unordered_map<int, int> &A, int number) {
  bool result = false;
  if (A[number] == number) {
    result = true;
  }
  return result;
}
unordered_map<int, int> check_vector(unordered_map<int, int> &map, int X) {
  unordered_map<int, int> result;
  for (int i = 1; i < X + 1; i++) {
    if (check_map(map, i) == false) {
      result[i] = i;
    }
  }
  return result;
}
int FrogRiverOne(vector<int> &A, int X) {
  unordered_map<int, int> map;
  unordered_map<int, int> check;
  int check2 = 0;
  for (int i = 0; i < A.size(); i++) {
    map[A[i]] = A[i];
    if (check[A[i]] == A[i]) {
      check.erase(A[i]);
    } else{
      check.erase(A[i]);
    }
    if (check2 == 1 && check.size() == 0) {
      return i;
    }
    if (i == X - 1 && check2 == 0) {
      if (check_vector(map, X).size() == 0) {
        return i;
      }
      check = check_vector(map, X);
      check2 = 1;
    }
  }
  return -1;
}
