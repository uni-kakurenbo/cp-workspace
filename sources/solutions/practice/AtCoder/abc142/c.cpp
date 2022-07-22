#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  ll n; cin >> n;
  using P = pair<ll, ll>;
  vector<P> A(n);
  for(int i=0; i<n; i++) {
    ll a; cin >> a;
    A[i] = P (a, i+1);
  }
  sort(A.begin(), A.end(), [](P a, P b){ return a.first < b.first; });
  for(P& a : A) cout << a.second << " ";
  cout << endl;
  return 0;
}
