#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, l; cin >> n >> l;
  multiset<string> S;
  REP(i, n) {
    string s; cin >> s;
    S.insert(s);
  }
  FORA(s, S) {
    cout << s;
  }
  cout << endl;
  return 0;
}
