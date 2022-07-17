#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int MaxProfit(vector<int> &A) {
  if (A.empty()) {
    return 0;
  }
  int result = 0;
  int smallest = A[0];
  int biggest = 0;
  int new_smallest = 0;
  int new_biggest = 0;
  bool check;
  bool something = false;
  for (int i = 1; i < A.size(); i++) {
    check = false;
    if (A[i] < smallest && !biggest) {
      smallest = A[i];
    }
    if (A[i] < smallest && biggest && something == false) {
      new_smallest = A[i];
      check = true;
      something = true;
    }
    if (A[i] < smallest && biggest && A[i] < new_smallest && !check) {
      new_smallest = A[i];
    }
    if (A[i] > smallest && A[i] > biggest) {
      biggest = A[i];
      if (result < biggest - smallest) {
        result = biggest - smallest;
      }
    }
    if (A[i] > new_biggest && A[i] > new_smallest && something == true) {
      new_biggest = A[i];
      if (result < new_biggest - new_smallest) {
        result = new_biggest - new_smallest;
      }
      new_biggest = 0;
    }
  }
  return result;
}
