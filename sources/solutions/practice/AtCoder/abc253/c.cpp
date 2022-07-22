#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
#include<debug>
    using namespace Debug;
#else
    template<class T = nullptr_t, class S = nullptr_t> inline void debug(T = nullptr, S = nullptr) {}
#endif

using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    ll q; cin >> q;
    map<ll, ll> cnt;
    REP(i, q) {
        short com; cin >> com;
        if(com == 1) {
            ll x; cin >> x;
            cnt[x]++;
        }
        if(com == 2) {
            ll x, c; cin >> x >> c;
            cnt[x] -= min(c, cnt[x]);
            if(cnt[x] == 0) {
                cnt.erase(x);
            }
        }
        if(com == 3) {
            cout << cnt.rbegin()->first - cnt.begin()->first << endl;
        }
    }
    return 0;
}
