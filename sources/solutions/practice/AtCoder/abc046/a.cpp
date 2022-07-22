#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(a, b) a=max(a, b)
#define chmin(a, b) a=min(a, b)

int main() {
    set<int> s;
    REP(i, 3) {
        int a; cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
    return 0;
}
