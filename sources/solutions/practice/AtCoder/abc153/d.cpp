#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ALL(I) I.begin(), I.end()

signed main() {
  ll h; cin >> h;
  int i=0;
  while(h > 1) {
    h /= 2;
    i++;
  }
  ll ans = pow(2, i+1)-1;
  cout << ans << endl;
  return 0;
}
