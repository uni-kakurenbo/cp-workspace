#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int n; cin >> n;
  int m = n;
  int sum = 0;
  while(m) {
    sum += m%10;
    m/=10;
  }
  cout << (n%sum==0?"Yes":"No") << endl;
  return 0;
}
