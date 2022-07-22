#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  vector<ll> B(n);
  FORA(b, B) cin >> b;
  ll ans = B[0];
  REP(i, n-1) ans += min(B[i], B[i+1]);
  ans += B[n-2];
  cout << ans << endl;
  return 0;
}
