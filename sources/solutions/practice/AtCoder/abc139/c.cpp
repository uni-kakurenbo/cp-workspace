#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  vector<int> H(n);
  FORA(h, H) cin >> h;
  int ans=0;
  int con=0;
  REP(i, n) {
    if(H[i] >= H[i+1] && i < n-1) con++;
    else {
      ans = max(ans, con);
      con=0;
    }
  }
  cout << ans << endl;
  return 0;
}
