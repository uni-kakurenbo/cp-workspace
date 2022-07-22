#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
  ll n; cin >> n;
  deque<bool> a(n);
  REP(i, n) cin >> a[i];
  bool flipped = false;
  while(a.size() > 0) {
    if(a.back() == flipped) {
      a.pop_back();
    } else if(a.front() == flipped) {
      a.pop_front();
      flipped = !flipped;
    } else{
      break;
    }
  }
  cout << (a.size()<=0?"Yes":"No") << endl;
  return 0;
}
