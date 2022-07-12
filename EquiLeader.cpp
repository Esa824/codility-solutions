#include <bits/stdc++.h>
using namespace std;
int EquiLeader(vector<int> &A) {
  int n = A.size();
  map<int, int> map_left;
  map<int, int> map_right;
  int current_leader_left = -1;
  int current_leader_right = -1;
  vector<int> vector_left;
  vector<int> vector_right;
  for (int i = 0; i < n; i++) {
    if (!i) {
      vector_left.push_back(A[i]);
      map_left[A[i]]++;
      continue;
    }
    map_left[A[i]]++;
    if (map_left[A[i]] > 1 && map_left[A[i]] > map_left[current_leader_left]) {
      current_leader_left = A[i];
    }
    if (map_left[current_leader_left] <= (i + 1) / 2) {
      vector_left.push_back(-1);
      continue;
    }
    vector_left.push_back(current_leader_left);
  }
  reverse(A.begin(), A.end());
  for (int i = 0; i < n; i++) {
    if (!i) {
      vector_right.push_back(A[i]);
      map_right[A[i]]++;
      continue;
    }
    map_right[A[i]]++;
    if (map_right[A[i]] > 1 &&
        map_right[A[i]] > map_right[current_leader_right]) {
      current_leader_right = A[i];
    }
    if (map_right[current_leader_right] <= (i + 1) / 2) {
      vector_right.push_back(-1);
      continue;
    }
    vector_right.push_back(current_leader_right);
  }
  reverse(vector_right.begin(), vector_right.end());
  int result = 0;
  for (int i = 0; i < n - 1; i++) {
    if (vector_left[i] == -1 || vector_right[i + 1] == -1) {
      continue;
    }
    if (vector_left[i] == vector_right[i + 1]) {
      result++;
    }
  }
  return result;
}
int main() {
  vector<int> input = {0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
                       1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0,
                       1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0,
                       0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1,
                       0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0,
                       1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1};

  cout << EquiLeader(input);
}
