#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  ll n, k; cin >> n >> k;
  ll r = n%k;
  cout << min(r, abs(r-k)) << endl;
  return 0;
}
