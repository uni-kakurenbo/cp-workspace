#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

template <typename T>
using Matrix = vector<vector<T>>;

int main() {
    ll a, b; cin >> a >> b;
    ll x, y; cin >> x >> y;
    if(a == b+1) {
        cout << x << endl;
    } else if(b > a) {
        cout << min((b-a)*y+x, ((b-a)*2+1)*x) << endl;
    } else if (a == b) {
        cout << x << endl;
    } else {
        cout << min((a-b-1)*y+x, ((a-b-1)*2+1)*x) << endl;
    }
}
