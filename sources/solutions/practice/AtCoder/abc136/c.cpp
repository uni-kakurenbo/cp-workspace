#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  bool ans = true;
  vector<int> h(n);
  FORA(a, h) cin >> a;
  REP(i, n-1) {
    int& next = h[i+1];
    int now = h[i];
    if(now <= next);
    else if(now == next+1) next++;
    else { ans = false; break; }
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
