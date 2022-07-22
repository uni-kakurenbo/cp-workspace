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

template<class T> vector<T> divisors(T n) {
    vector<T> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) res.emplace_back(n / i);
        }
    }
    sort(ALL(res));
    return res;
}

vector<vector<ll>> mdiv(21);

ll solve(string n) {
    ull len = n.size();
    ll ans = -1;
    vector<ll>& div = mdiv[len];
    FOR(i, 0, div.size()-2) {
        ull d = div[i];
      	ull r = len/d;
        string t = n.substr(0, d);
        string p = "";
      	REP(i, r) p += t;
        if(p > n) {
            p = "";
            t = to_string(stoll(t)-1);
            if(t.size() < d or t == "0") {
                chmax(ans, stoll(string(len-1, '9')));
                continue;
            }
      	    REP(i, r) p += t;
        }
        chmax(ans, stoll(p));
    }
    return ans;
}

signed main() {
    FOR(i, 1, 20) mdiv[i] = divisors(i);

    ull t; cin >> t;
    REP(i, t) {
        string n; cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
