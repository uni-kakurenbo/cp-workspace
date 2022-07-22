#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  ll n; cin >> n;
  ll prev2 = 2;
  ll prev1 = 1;
  ll ans = 1;
  FOR(i, 2, n) {
    ans = prev1 + prev2;
    prev2 = prev1;
    prev1 = ans;
  }
  cout << ans << endl;
  return 0;
}
