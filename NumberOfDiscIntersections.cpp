#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int NumberOfDiscIntersections(vector<int> &A) {
  vector<double> start;
  vector<double> end;
  int result = 0;
  int k = 0;
  int open_discs = 0;
  for (int i = 0; i < A.size(); i++) {
    double index1 = A[i];
    index1 = i - index1;
    double index2 = A[i];
    index2 += i;
    start.push_back(index1);
    end.push_back(index2);
  }
  sort(start.begin(), start.end());
  sort(end.begin(), end.end());
  for (int i = 0; i < A.size(); i++) {
    for (int j = k; j < A.size(); j++) {
      if (start[i] <= end[j]) {
        result += open_discs;
        if (result > 10000000) {
          return -1;
        }
        open_discs++;
        break;
      }
      open_discs--;
      k++;
    }
  }
  return result;
}
int main() { vector<int> input = {1, 5, 2, 1, 4, 0}; 
  cout << NumberOfDiscIntersections(input);
}
