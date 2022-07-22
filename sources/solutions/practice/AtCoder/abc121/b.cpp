#include<bits/stdc++.h>
using namespace std;

signed main() {
  int n, m, c; cin >> n >> m >> c;
  vector<int> B(m);
  for(int& b : B) cin >> b;
  int ans = 0;
  for(int i=0; i<n; i++) {
    int sum = c;
    for(int j=0; j<m; j++) {
      int a; cin >> a;
      sum += a*B[j];
    }
    if(sum > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
