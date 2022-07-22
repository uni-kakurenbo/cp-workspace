#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  map<string, int> M;
  REP(i, n) {
    string name; cin >> name;
    M[name]++;
  }
  int e = 0;
  FORA(m, M) {
    e = max(e, m.second);
  }
  FORA(m, M) {
    if(m.second == e) {
      cout << m.first << endl;
    }
  }
  return 0;
}
