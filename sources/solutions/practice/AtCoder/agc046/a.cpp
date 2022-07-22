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
    int x; cin >> x;
    int dir = 0;
    ll ans = 0;
    while(true) {
        dir += x;
        dir %= 360;
        ans++;
        if(dir == 0) break;
    }
    cout << ans << endl;
}
