#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string S; cin >> S;
  int ans0 = 0;
  REP(i, S.length()) {
    if(i%2 == 0 && S[i] == '0') ans0++;
    if(i%2 == 1 && S[i] == '1') ans0++;
  }
  int ans1 = 0;
  REP(i, S.length()) {
    if(i%2 == 0 && S[i] == '1') ans1++;
    if(i%2 == 1 && S[i] == '0') ans1++;
  }
  cout << min(ans0, ans1) << endl;
  return 0;
}
