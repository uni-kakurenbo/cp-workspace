#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  int n; cin >> n;
  vector<float> V(n);
  for(float& v : V) cin >> v;
  sort(V.begin(), V.end());
  ll ans = 0;
  for(int i=1; i<n; i++) {
    V[i] = (V[i-1]+V[i])/2;
  }
  cout << fixed << setprecision(12);
  cout << V[n-1] << endl;
  return 0;
}
