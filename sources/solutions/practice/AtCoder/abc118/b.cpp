#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, m; cin >> n >> m;
  map<int, int> M;
  REP(i, n) {
    int k; cin >> k;
    REP(j, k) {
      int a; cin >> a;
      M[a]++;
    }
  }
  int ans = 0;
  FORA(x, M) {
    if(x.second == n) ans++;
  }
  cout << ans << endl;
  return 0;
}
