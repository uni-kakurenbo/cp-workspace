#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string S; cin >> S;
  bool ans = 
   ((S.find('N') == string::npos) ^
    (S.find('S') == string::npos)) ||
   ((S.find('E') == string::npos) ^
    (S.find('W') == string::npos));
  cout << (!ans?"Yes":"No") << endl;
  return 0;
}
