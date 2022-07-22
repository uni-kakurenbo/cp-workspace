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
    int l, r, d; cin >> l >> r >> d;
    int ans = 0;
    FOR(i, l, r) {
        if(i%d == 0) ++ans;
    }
    printf("%i\n", ans);
    return 0;
}
