#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
#include<debug>
    using namespace Debug;
#else
    template<class T = nullptr_t, class S = nullptr_t> inline void debug(T = nullptr, S = nullptr) {}
#endif

using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

ll cnt(ll n, ll x) {
    return (x+n-n%x)*(n/x)/2;
}

signed main() {
    ll n, a, b; cin >> n >> a >> b;
    cout << n*(n+1)/2 - cnt(n, a) - cnt(n, b) + cnt(n, lcm(a,b)) << endl;
    return 0;
}
