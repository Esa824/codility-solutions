#include <bits/stdc++.h>
using namespace std;
int fish(vector<int> &A, vector<int> &B) {
  int indexof_biggest_size_of_fish = 0;
  int biggest_size_of_fish = 0;
  for (int i = 0; i < A.size(); i++) {
    if (biggest_size_of_fish < A[i]) {
      biggest_size_of_fish = A[i];
      indexof_biggest_size_of_fish = i;
    }
  }
  int result = 0;
  for (int i = 0; i < A.size(); i++) {
    if (B[i] != B[indexof_biggest_size_of_fish]) {
      result++;
    }
  }
  return result + 1;
}
int main() {
  vector<int> input1 = {4, 3, 2, 1, 5};
  vector<int> input2 = {0, 1, 0, 0, 0};
  cout << fish(input1, input2);
}
