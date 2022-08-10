#include <bits/stdc++.h>
using namespace std;
int MinPerimeterRectangle(int N) {
  int result = 0;
  bool set = false;
  for (int i = 1; i < sqrt(N) + 1; i++) {
    int equal = N / i;
    equal += i;
    equal *= 2;
    if (N % i == 0 && result > equal || N % i == 0 && set == false) {
      result = equal;
      set = true;
    }
  }
  if (result) {
    return result;
  } else {
    return 4;
  }
}
