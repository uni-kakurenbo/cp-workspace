#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  vector a(2, vector<int> (n));
  REP(i, 2) REP(j, n) cin >> a[i][j];
  int ans = 0;
  REP(i, n) {
    int sum = 0;
    REP(j, n) {
      if(j <= i) sum += a[0][j];
      if(j >= i) sum += a[1][j];
    }
    //cout << sum << endl;
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
