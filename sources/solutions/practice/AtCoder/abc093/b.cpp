#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int a, b, k; cin >> a >> b >> k;
  set<int> A;
  FOR(i, a, b) {
    if(i < a+k || b-k < i) cout << i << endl;
  }
  return 0;
}
