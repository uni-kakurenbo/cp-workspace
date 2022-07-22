#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    ll n; cin >> n;
    set<string> already;
    already.insert("-1");
    pair<ll, ll> ans;
    REP(i, n) {
        string s; ll t; cin >> s >> t;
        if(*already.lower_bound(s) != s) {
            if(ans.first < t) ans = make_pair(t, i);
            already.insert(s);
        }
    }
    cout << ans.second+1 << endl;
    return 0;
}
