#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int a, b; cin >> a >> b;
  if(a <= 0 && 0 <= b) cout << "Zero";
  else if(a > 0 && b > 0) cout << "Positive";
  else if(a < 0 && b < 0) {
    if((b-a)%2 == 1)
      cout << "Positive";
    else
      cout << "Negative";
  }
  cout << endl;
  return 0;
}
