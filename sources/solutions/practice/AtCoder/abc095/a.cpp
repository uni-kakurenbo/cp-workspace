#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int a, b, c; cin >> a >> b >> c;
  int x, y; cin >> x >> y;
  int m = min(x, y);
  int ans = 0;
  if(a+b < c*2) ans += m*(a+b);
  else ans += m*c*2;
  if(a < c*2) ans += a*(x-m);
  else ans += 2*c*(x-m);
  if(b < c*2)ans += b*(y-m);
  else ans += 2*c*(y-m);
  cout << ans << endl;
  return 0;
}
