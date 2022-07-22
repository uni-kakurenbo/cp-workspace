#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

int main() {
    ll a, b, c; cin >> a >> b >> c;
    vector<ll> v = {a, b, c};
    sort(ALL(v));
    ll x = v[2]/2, y = (v[2]+1)/2;
    ll ans = (y-x)*v[0]*v[1];
    cout << ans << endl;
    return 0;
}
