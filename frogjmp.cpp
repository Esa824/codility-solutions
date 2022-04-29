#include <iostream>
#include <vector>
using namespace std;
int frogjmp(int X, int Y, int D) {
  int result2 = Y / D * D;
  result2 = result2 < Y &&result2 != Y ? result2 += D : result2;
  result2 += X;
  while (result2 > Y) {
    result2 -= D;
  }
  result2 = result2 != Y ? result2 += D : result2;
  result2 -= X;
  return result2 / D;
}
