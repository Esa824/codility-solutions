#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include <regex>
#include <string>
#include <unistd.h>
using namespace std;
bool binarySearch(const vector<int>& array, int x, int xx, int low, int high) {

  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] >= x && array[mid] <= xx)
      return true;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return false;
}
vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int>& Q) {
  vector<int> result(P.size());
  vector<int> A;
  vector<int> C;
  vector<int> G;
  for (size_t i = 0; i < S.size(); i++) {
    if (S[i] == 'A') {
      A.push_back(i);
    } else if (S[i] == 'C') {
      C.push_back(i);
    } else if (S[i] == 'G') {
      G.push_back(i);
    }
  }
  for (size_t i = 0; i < P.size(); i++) {
    if(result[i] != 0){
      continue;
    }
    if (A.size()) {
      bool result1 = binarySearch(A, P[i], Q[i], 0, A.size() - 1);
      if (result1) {
        result[i] = 1;
        continue;
      }
    }
    if (C.size()) {
      bool result2 = binarySearch(C, P[i], Q[i], 0, C.size() - 1);
      if (result2) {
        result[i] = 2;
        continue;
      }
    }
    if (G.size()) {
      bool result3 = binarySearch(G, P[i], Q[i], 0, G.size() - 1);
      if (result3) {
        result[i] = 3;
        continue;
      }
    }
    result[i] = 4;
  }
  return result;
}
