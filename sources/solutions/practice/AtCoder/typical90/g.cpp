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
    int h, w; cin >> h >> w;
    if(h == 1 || w == 1) printf("%i\n", max(h, w));
    else printf("%i\n", ((h+1)/2) * ((w+1)/2));
    return 0;
}
