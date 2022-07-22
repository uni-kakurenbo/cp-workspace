#include<bits/stdc++.h>
using namespace std;

signed main() {
  int s; cin >> s;
  int next = s;
  int i = 1;
  while(true) {
    int a = next;
    if(a == 4 || a == 2 || a == 1) break;
    next = a%2 ? a*3+1 : a/2;
    i++;
  }
  cout << i+3 << endl;
  return 0;
}
