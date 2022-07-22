#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/...>
// using namespace atcoder;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define INF32 2147483647
#define INF64 9223372036854775807LL

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPD(i,n) for(int i=n-1; i>=0; --i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORD(i,a,b) for(ll i=a i##_stop=ll(b); i>=i##_stop; --i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n); REP(i, n) cin >> v[i];

    auto is_satisfied = [&](ll x) {
        ll p = 0, q = 0;
        REP(i, n) {
            if(v[i] < x) p += (x-v[i] + a - 1) / a;
            else q += (v[i]-x) / b;
        };
        // debug(p, q);
        return p <= q;
    };

    ll ng = INF32, ok = -1;
    while(abs(ok-ng) > 1) {
        ll mid = (ok+ng) / 2;
        // debug(mid);
        (is_satisfied(mid) ? ok : ng) = mid;
    }

    cout << ok << "\n";

    return 0;
}
