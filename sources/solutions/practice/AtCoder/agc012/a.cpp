#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  int m = n*3;
  vector<int> A(m);
  FORA(a, A) cin >> a;
  sort(ALL(A), greater<int>{});
  ll ans = 0;
  REP(i, n) ans += A[2*i+1];
  cout << ans << endl;
  return 0;
}
