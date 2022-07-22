#include<bits/stdc++.h>
using namespace std;

signed main() {
  long long h, w;
  cin >> h >> w;
  if(h == 1 || w == 1) cout << 1;
  else cout << (h*w+(h%2&&w%2))/2;
  cout << endl;
  return 0;
}
