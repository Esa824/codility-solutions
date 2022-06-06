#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int StoneWall(vector<int> &H) {
  stack<int> stack;
  int counter = 0;
  for (size_t i = 0; i < H.size(); i++) {
    if (!stack.empty()) {
      while (stack.top() > H[i]) {
        stack.pop();
        if(stack.empty()){
          break;
        }
      }
    }
    if (stack.empty()) {
      counter++;
      stack.push(H[i]);
      continue;
    }
    if (H[i] > stack.top()) {
      counter++;
      stack.push(H[i]);
    }
  }
  return counter;
}
