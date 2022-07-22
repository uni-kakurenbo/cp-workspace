#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int x; cin >> x;
  ll ans = 0;
  FOR(b, 1, 350) {
    FOR(p, 2, 10) {
      ll v = pow(b, p);
      if(v <= x) ans = max(ans, v);
    }
  }
  cout << ans << endl;
  return 0;
}
