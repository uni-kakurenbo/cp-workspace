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

int main() {
    ll n; cin >> n;
    vector<ll> a(n), sum(n+1, 0);
    REP(i, n) cin >> a[i];
    REP(i, n) sum[i+1] = sum[i] + a[i];

    ll ans = 1LL << 60;
    REP(i, n) {
        chmin(ans, abs(sum[n] - 2*sum[i]));
    }
    printf("%lli\n", ans);
    return 0;
}
