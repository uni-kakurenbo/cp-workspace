#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string s, t; cin >> s >> t;
  bool ans = false;
  REP(i, s.size()) {
    if(s == t) {
      ans = true;
      break;
    }
    rotate(s.begin(), s.begin()+1, s.end());
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
