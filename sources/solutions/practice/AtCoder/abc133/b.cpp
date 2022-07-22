#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, d; cin >> n >> d;
  vector P(n, vector<ll>(d));
  FORA(V, P) FORA(x, V) cin >> x;
  int ans = 0;
  FOR(i, 0, n-2) {
    FOR(j, i+1, n-1) {
      ll sum=0;
      REP(k, d) sum += (P[i][k]-P[j][k])*(P[i][k]-P[j][k]);
      ll dist = floor(sqrt((double)sum));
      if(dist*dist == sum) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
