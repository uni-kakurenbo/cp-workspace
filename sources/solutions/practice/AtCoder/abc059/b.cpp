#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  string a, b;
  cin >> a >> b;
  string ans = "EQUAL";
  if(a.size() == b.size()) {
    if(a > b) ans = "GREATER";
    else if(a < b) ans = "LESS";
  } else {
    if(a.size() > b.size()) ans = "GREATER";
    else ans = "LESS";
  }
  cout << ans << endl;
  return 0;
}
