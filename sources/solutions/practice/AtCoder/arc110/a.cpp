#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(a, b) a=max(a, b)
#define chmin(a, b) a=min(a, b)


vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()) IsPrime.resize(max+1,true);
    IsPrime[0] = IsPrime[1] = false;
    for(size_t p=2; p*p<=max; p++) if(IsPrime[p]) for(size_t i=p*p; i<=max; i+=p) IsPrime[i] = false;
}

int main() {
    int n; cin >> n;
    sieve(100);
    ll f = 1;
    FOR(i, 2, n) {
        f = lcm(f, i);
    }
    cout << f + 1 << endl;
    return 0;
}
