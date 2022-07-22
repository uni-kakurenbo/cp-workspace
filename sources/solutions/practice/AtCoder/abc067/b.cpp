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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a), greater<int> {});
    ll sum = 0;
    REP(i, k) sum += a[i];
    printf("%lli\n", sum);
    return 0;
}
