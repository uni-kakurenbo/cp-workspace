#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int w, a, b; cin >> w >> a >> b;
  if(a+w < b)
  	cout << b-(a+w);
  else if(b+w < a)
  	cout << a-(b+w);
  else cout << 0;
  cout << endl;
}
