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

bool isNG (int base, ll x) {
    while(x > 0) {
        if(x%base == 7) return true;
        x /= base;
    }
    return false;
}

int main() {
    ll n; cin >> n;
    ll ans = n;
    FOR(i, 1, n) {
        ans -= isNG(10, i) || isNG(8, i);
    }
    printf("%lli\n", ans);
    return 0;
}
