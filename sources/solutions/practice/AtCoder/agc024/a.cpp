#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if(k%2) cout << b-a;
  else cout << a-b;
  cout << endl;
  return 0;
}
