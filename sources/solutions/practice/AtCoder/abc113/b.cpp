#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; double t, a;
  cin >> n >> t >> a;
  double m = 10000000000;
  int ans;
  REP(i, n) {
    double h; cin >> h;
    double diff = abs(t-0.006*h - a);
    if(diff < m) {
      ans = i+1;
      m = diff;
    }
  }
  cout << ans << endl;
  return 0;
}
