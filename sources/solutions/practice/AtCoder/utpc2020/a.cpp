#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FORD(i,a,b) for(ll i=a; i>=ll(b); i--)

using Tent = pair<ll,ll>;

int main() {
    ll n, l; cin >> n >> l;

    vector<Tent> tents;
    REP(i,n) {
        ll x, a; cin >> x >> a;
        tents.emplace_back(x,a);
    }

    ll t = 0;
    ll ans = 0;
    FORD(i, n-1, 1) {
        Tent tent = tents[i];
        t += tent.second;
        ans = max(ans, t);
        t = max(0LL, t - tent.first + tents[i-1].first);
    }
    t += tents[0].second;
    ans = max(ans, t);

    cout << ans << endl;

    return 0;
}
