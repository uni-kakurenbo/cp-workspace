#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  ll n; cin >> n;
  vector<ll> D(n);
  for(ll& d : D) cin >> d;
  sort(D.begin(), D.end());
  ll ans = D[n/2] - D[n/2-1];
  cout << ans << endl;
  return 0;
}
