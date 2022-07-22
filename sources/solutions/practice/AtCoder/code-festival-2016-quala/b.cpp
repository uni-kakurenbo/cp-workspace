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
    vector<ll> A(n);
    REP(i, n) cin >> A[i];
    REP(i, n) --A[i];
    ll ans = 0;
    REP(i, n) {
        if(i == A[A[i]]) ++ans;
    }
    cout << ans/2 << endl;
}
