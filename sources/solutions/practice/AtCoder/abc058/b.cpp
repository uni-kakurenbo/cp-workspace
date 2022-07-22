#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string odd, even;
  cin >> odd >> even;
  REP(i, min(odd.size(), even.size())) {
    cout << odd[i] << even[i];
  }
  if(odd.size() > even.size()) cout << odd.back();
  cout << endl;
  return 0;
}
