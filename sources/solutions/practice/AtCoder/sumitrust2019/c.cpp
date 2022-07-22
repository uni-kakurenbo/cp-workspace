#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int x; cin >> x;
  vector<bool> dp(x+500, false);
  dp[0] = true;
  REP(i, x) {
    REP(j, 6) {
      if(dp[i]) dp[i+100+j] = true;
    }
  }
  cout << (int)dp[x] << endl;
  return 0;
}
