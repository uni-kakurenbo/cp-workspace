#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  ll k, n; cin >> k >> n;
  vector<ll> dists(n);
  ll prev = 0;
  for(ll& d : dists) {
    int a; cin >> a;
    d = a - prev;
    prev = a;
  }
  dists[0] = dists[0] + k - prev;
  auto max = max_element(dists.begin(), dists.end());
  cout << k - *max << endl;
  return 0;
}
