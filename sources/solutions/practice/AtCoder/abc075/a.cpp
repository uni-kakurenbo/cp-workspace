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
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b) printf("%i\n", c);
    if(b == c) printf("%i\n", a);
    if(c == a) printf("%i\n", b);
    return 0;
}
