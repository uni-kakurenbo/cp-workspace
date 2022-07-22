#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(const auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, k, q; cin >> n >> k >> q;
  vector V(n, k);
  REP(i, q) {
    int a; cin >> a;
    V[--a]++;
  }
  FORA(v, V) {
    if(v > q) cout << "Yes";
    else cout << "No";
    cout << endl;
  }
  return 0;
}
