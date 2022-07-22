#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  ll n; cin >> n;
  ll r = sqrt(n);
  ll ans = 1LL << 60;
  FOR(a, 1, r+1) {
    ll b = n/a;
    if(a*b != n) continue;
    ans = min(a+b-2, ans);
  }
  cout << ans << endl;
  return 0;
}
