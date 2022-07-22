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
    ll n, m; cin >> n >> m;
    set<ll> prob;
    map<ll, ll> cnt;
    ll ans_min = 1LL << 60;
    ll ans_max = 0;
    REP(i, n) {
        int a; cin >> a;
        cnt[a]++;
        prob.insert(a);
    }
    if(prob.size() < m) ans_min = 0;
    FORA(p, prob) {        
        chmin(ans_min, cnt[p]);
        chmax(ans_max, cnt[p]);
    }
    cout << ans_min << " ";
    cout << ans_max << endl;
    return 0;
}
