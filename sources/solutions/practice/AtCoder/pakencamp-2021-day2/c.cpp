#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) a = max(t, c)
#define chmin(t, c) a = min(t, c)

int main() {
    int n, m;  cin >> n >> m;
    set<int> a, b, ans;
    REP(i, n) {
        int v; cin >> v;
        a.insert(v);
    }
    REP(i, m) {
        int v; cin >> v;
        if(binary_search(ALL(a), v)) continue;
        ans.insert(v);
    }
    cout << ans.size() << endl;
    FORA(v, ans) cout << v << endl;
    
    return 0;
}
