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
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int h, w; cin >> h >> w;
    int c, q; cin >> c >> q;

    vector<tuple<int,int,int>> queries;
    REP(i, q) {
        int t, n, x; cin >> t >> n >> x; --n, --x;
        queries.emplace_back(t, n, x);
    }
    reverse(ALL(queries));
    debug(queries);

    vector<ll> ans(c);
    int a = 0, b = 0;
    set<int> u, v;
    u.emplace(INF32), v.emplace(INF32);
    for(auto& [t, n, x] : queries) {
        if(t == 1) {
            if(*u.lower_bound(n) == n) continue;
            u.emplace(n);
            ans[x] += w - b;
            ++a;
        }
        if(t == 2) {
            if(*v.lower_bound(n) == n) continue;
            v.emplace(n);
            ans[x] += h - a;
            ++b;
        }
        debug(u, v); debug(ans);
    }

    FORA(v, ans) cout << v << " ";

    return 0;
}
