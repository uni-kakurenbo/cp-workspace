#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> bool chmax(T& a, T b) { a = std::max(a, b); return a < b; }
template<class T> bool chmin(T& a, T b) { a = std::min(a, b); return a > b; }

signed main() {
    ll x, k, d; cin >> x >> k >> d;
    x = abs(x);
    ll move = x/d;
    chmin(move, k);
    x -= move * d;
    k -= move;
    if (k%2 == 1) x = d-x;
    printf("%lli\n", x);
    return 0;
}
