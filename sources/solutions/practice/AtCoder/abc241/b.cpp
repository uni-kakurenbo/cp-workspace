#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n, m; cin >> n >> m;
  map<int, int> A;
  REP(i, n) {
    int a; cin >> a;
    A[a]++;
  }
  bool ans = true;
  REP(i, m) {
    int b; cin >> b;
    if(A[b]) {
      A[b]--;
    } else {
      ans = false; break;
    }
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
