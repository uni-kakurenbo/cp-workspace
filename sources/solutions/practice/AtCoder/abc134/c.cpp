#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  vector<int> A(n);
  FORA(a, A) cin >> a;
  vector<int> B = A;
  sort(ALL(B), greater<int>{});
  REP(i, n) {
    if(A[i] == B[0]) cout << B[1];
    else cout << B[0];
    cout << endl;
  }
  return 0;
}
