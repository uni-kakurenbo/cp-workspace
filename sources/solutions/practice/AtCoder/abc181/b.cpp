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
    ll sum = 0;
    REP(i, n) {
        ll a, b; cin >> a >> b;
        sum += b*(b+1)/2 - a*(a-1)/2;
    }
    printf("%lli\n", sum);
    return 0;
}
