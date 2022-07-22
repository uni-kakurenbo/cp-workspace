#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  int n; cin >> n;
  int fl = floor((double)n / 1.08);
  int ce = ceil((double)n / 1.08);
  if(floor(fl * 1.08) == n) cout << fl;
  else if(floor(ce * 1.08) == n) cout << ce;
  else cout << ":(";
  cout << endl;
  return 0;
}
