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
    ll n, a, b; cin >> n >> a >> b;
    ll l = a*(n-1) + b;
    ll r = b*(n-1) + a;
    cout << max(r-l + 1, 0ll) << endl;
    return 0;
}
