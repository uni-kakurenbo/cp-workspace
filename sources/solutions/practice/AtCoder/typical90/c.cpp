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
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    REP(i, n) a[i] %= p;
    ll ans = 0;
    FOR(i1, 0, n-5)
        FOR(i2, i1+1, n-4)
            FOR(i3, i2+1, n-3)
                FOR(i4, i3+1, n-2)
                    FOR(i5, i4+1, n-1) {
                        ll product = a[i1];
                        product *= a[i2];
                        product %= p;
                        product *= a[i3];
                        product %= p;
                        product *= a[i4];
                        product %= p;
                        product *= a[i5];
                        product %= p;
                        if(product == q) ++ans;
                    }
    printf("%lli\n", ans);
    return 0;
}
