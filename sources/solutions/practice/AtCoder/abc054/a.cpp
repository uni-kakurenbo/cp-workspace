#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

signed main() {
  int a, b; cin >> a >> b;
  a--, b--;
  vector<int> st = {13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  if(a == b) cout << "Draw";
  else cout << (st[a]>st[b]?"Alice":"Bob");
  cout << endl;
  return 0;
}
