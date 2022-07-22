#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  ll n, k; cin >> n >> k;
  vector<ll> T(n);
  FORA(t, T) cin >> t;
  sort(ALL(T));
  ll ans = pow(10, 10);
  REP(i, n-k+1) {
    ll diff = T[i+k-1] - T[i];
    ans = min(ans, diff);
  }
  cout << ans << endl;
  return 0;
}
