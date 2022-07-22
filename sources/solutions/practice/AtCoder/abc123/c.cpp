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
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vector T = { a, b, c, d, e };
    sort(ALL(T));
    cout << 4 + (n+T[0]-1)/T[0] << endl;
    return 0;
}
