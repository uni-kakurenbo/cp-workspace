#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  using I = pair<string, int>;
  using P = pair<I, int>;
  vector<P> R(n);
  REP(i, n) {
    string s; int p;
    cin >> s >> p;
    R[i] = P (I (s, -p), i+1);
  }
  sort(ALL(R));
  FORA(r, R) {
    cout << r.second << endl;
  }
  return 0;
}
