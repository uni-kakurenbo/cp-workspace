#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ALL(I) I.begin(), I.end()

signed main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll s = n/(a+b);
  ll ans = s*a;
  ll d = n-s*(a+b);
  if(d <= a) ans += d;
  else ans += a;
  cout << ans << endl;
  return 0;
}
