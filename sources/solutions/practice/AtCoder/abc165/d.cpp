#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    ll a, b, n; cin >> a >> b >> n;
    auto f = [&](ll x){ return (a*x)/b - a*(x/b); };
    ll ans = 0;
    chmax(ans, f(n));
    if (b-1 <= n) chmax(ans, f(b-1));
    cout << ans << endl;
    return 0;
}
