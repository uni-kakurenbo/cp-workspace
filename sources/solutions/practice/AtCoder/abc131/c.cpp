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

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = b-a+1;
    ans -= (b/c-(a-1)/c) + (b/d-(a-1)/d) - (b/lcm(c, d)-(a-1)/lcm(c, d));
    printf("%lli\n", ans);
    return 0;
}
