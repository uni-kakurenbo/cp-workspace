#include<bits/stdc++.h>
using namespace std;

signed main() {
  vector A(3, vector<int> (3));
  for(auto& a_i : A)
    for(int& a : a_i) cin >> a;
  int n; cin >> n;
  set<int> B;
  for(int i=0; i<n; i++) {
    int b; cin >> b;
    B.insert(b);
  }
  auto f = [&](int i, int j) {
    return B.find(A[i][j]) != B.end();
  };
  if(
  	(f(0, 0) && f(0, 1) && f(0, 2)) ||
  	(f(1, 0) && f(1, 1) && f(1, 2)) ||
  	(f(2, 0) && f(2, 1) && f(2, 2)) ||

  	(f(0, 0) && f(1, 0) && f(2, 0)) ||
  	(f(0, 1) && f(1, 1) && f(2, 1)) ||
  	(f(0, 2) && f(1, 2) && f(2, 2)) ||

  	(f(0, 0) && f(1, 1) && f(2, 2)) ||
  	(f(0, 2) && f(1, 1) && f(2, 0))
  ) cout << "Yes";
  else cout << "No";
  cout << endl;
  return 0;
}
