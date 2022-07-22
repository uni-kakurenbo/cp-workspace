#include<bits/stdc++.h>
using namespace std;

signed main() {
  int n, m, x;
  cin >> n >> m >> x;
  int l=0, r=0;
  for(int i=0; i<m; i++) {
    int a; cin >> a;
    if(a < x) l++;
    else r++;
  }
  cout << min(l, r) << endl;
  return 0;
}
