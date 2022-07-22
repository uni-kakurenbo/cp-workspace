#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int a, b; cin >> a >> b;
  int ans = -1;
  REP(i, pow(10, 4)+100) {
    if(floor((double)i*0.08) == a &&
      floor((double)i*0.10) == b) {
      ans = i; break;
    }
  }
  cout << ans << endl;
  return 0;
}
