#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

inline ll ctz(ll x) {
    ll res = 0;
    while(x%2 == 0) {
        ++res;
        x /= 2;
    }
    return res;
}


int main() {
    ll n; cin >> n;
    vector<ll> T(n);
    REP(i, n) cin >> T[i];
    ll current = 0;
    FORA(t, T) {
      	current = (((current >> t) + 1) | 1) << t;
    }
    printf("%lli\n", current);
    return 0;
}
