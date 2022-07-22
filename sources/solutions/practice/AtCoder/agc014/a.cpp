#include<bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if(a == b && b == c) {
    if(a%2 == 0) {
      cout << -1;
    } else {
      cout << 0;
    }
  } else {
    ll ans = 0;
    while(!(a%2 || b%2 || c%2)) {
      ll ta=a, tb=b, tc=c;
      a = (tb+tc)/2;
      b = (tc+ta)/2;
      c = (ta+tb)/2;
      ans++;
    }
    cout << ans;
  }
  cout << endl;
  return 0;
}
