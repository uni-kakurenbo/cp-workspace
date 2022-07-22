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

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2*100000+10;

signed main() {
  ll n; cin >> n;
  vector<ll> a(n), cnt(MAX);
  REP(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  ll ans = n*(n-1)*(n-2)/6;
  REP(i, MAX) {
    ans -= cnt[i]*(cnt[i]-1)/2*(n-cnt[i]);
    ans -= cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
  }
  cout << ans << endl;
  return 0;
}
