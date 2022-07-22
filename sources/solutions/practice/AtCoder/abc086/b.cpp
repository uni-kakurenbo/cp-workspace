#include<bits/stdc++.h>
using namespace std;

signed main() {
  string a, b; cin >> a >> b;
  int ab = stoi(a+b);
  int root = sqrt(ab);
  cout << (root*root==ab?"Yes":"No") << endl;
  return 0;
}
