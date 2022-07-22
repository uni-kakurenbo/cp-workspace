#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(const auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, m; cin >> n >> m;
  int l_max = 0, r_min = n+1;
  REP(i, m) {
    int l, r; cin >> l >> r;
    l_max = max(l_max, l);
    r_min = min(r_min, r);
  }
  int ans = r_min-l_max+1;
  if(ans > 0) cout << ans;
  else cout << 0;
  cout << endl;
  return 0;
}
