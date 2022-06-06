#include <bits/stdc++.h>
using namespace std;
int Nesting(vector<int> &S) {
  if (S.size() % 2 == 1) {
    return 0;
  }
  stack<char> stack;
  for (size_t i = 0; i < S.size(); i++) {
    if (S[i] == '(') {
      stack.push(S[i]);
    }
    if (stack.top() == '(' && S[i] == ')') {
      stack.pop();
    }
  }
  if (stack.empty()) {
    return 1;
  } else {
    return 0;
  }
}
