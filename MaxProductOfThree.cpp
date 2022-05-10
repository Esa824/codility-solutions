#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int MaxProductOfThree(vector<int> &A) {
  int n = A.size();
	sort(A.begin(), A.end());
	return max(A[0] * A[1] * A[n - 1],
			A[n - 1] * A[n - 2] * A[n - 3]);
}
