#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

int main() {
    ll n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    REP(i, n) cin >> c[i];
    REP(i, n) --c[i];
    map<ll, ll> d, e;
    REP(i, n) {
        d[b[c[i]]]++;
        e[a[i]]++;
    }
    ll ans = 0;
    for(auto [k, v] : d) {
        ans += v*e[k];
    }
    printf("%lli\n", ans);
}
