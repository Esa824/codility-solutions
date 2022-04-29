#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int Binary_tree_gap(int N) {
  string a;
  int n = N;
  while (n) {
    a += (n % 2) + '0';
    n /= 2;
  }
  reverse(a.begin(), a.end());
  const char *b = a.c_str();
  const char *c = b;
  c++;
  const char*mm = b;
  int check = 0;
  while(*mm != 0){
    if(*mm == '0'){
      check = 1;
    }
    mm++;
  }
  if(check == 0){
    return 0;
  }
  int lenth = 0;
  int longest_lenth = 0;
  while (*c != 0) {
    if (*c == '1') {
      if (longest_lenth < lenth) {
        longest_lenth = lenth;
      }
      lenth = 0;
      c++;
    }
    c++;
    lenth++;
  }
  return longest_lenth;
}
