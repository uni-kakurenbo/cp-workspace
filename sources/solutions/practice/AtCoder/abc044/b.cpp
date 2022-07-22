#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string w; cin >> w;
  map<char, int> M;
  FORA(s, w) M[s]++;
  bool ans = true;
  FORA(m, M) {
    if(m.second%2) {
      ans = false; break;
    }
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
