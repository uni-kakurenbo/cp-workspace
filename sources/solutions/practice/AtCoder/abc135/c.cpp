#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  vector<ll> A(n+1), B(n+2, 0);
  FORA(v, A) cin >> v;
  REP(i, n) cin >> B[i+1];
  ll ans = 0;
  REP(i, n+1) {
    ll a = A[i], b = B[i];
    ans += min(a, b);
    A[i] -= min(a, b), B[i] -= min(a, b);

    a = A[i], b = B[i+1];
    ans += min(a, b);
    A[i] -= min(a, b), B[i+1] -= min(a, b);
  }
  cout << ans << endl;
  return 0;
}
