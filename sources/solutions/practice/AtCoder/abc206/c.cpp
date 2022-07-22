#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define All(x) x.begin(),x.end()

#define chmax(a, b) a=max(a, b)
#define chmin(a, b) a=min(a, b)


int main() {
    ll n; cin >> n;
    ll ans = n * (n-1)/2;
    map<ll, ll> mp;
    REP(i, n) {
        ll a; cin >> a;
        mp[a]++;
    }
    for(auto [k, v] : mp) {
        if(v <= 1) continue;
        ans -= v * (v-1)/2;
    }
    cout << ans << endl;
    return 0;
}
