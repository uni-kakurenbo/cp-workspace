#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin >> n;
  vector<ll> X(n);
  for(ll& x : X) cin >> x;
  ll ans = 1000000;
  for(ll p=0; p<=100; p++) {
    ll h=0;
    for(ll& x : X) h += (x-p)*(x-p);
    ans = min(ans, h);
  }
  cout << ans << endl;
}
