#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int CountFactors(int N) {
  int result = 0;
  for (int i = 1; i <= sqrt(N); i++) {
    if (N % i == 0) {
      if (N / i == i) {
        result++;
      } else {
        result += 2;
      }
    }
  }
  return result;
}
