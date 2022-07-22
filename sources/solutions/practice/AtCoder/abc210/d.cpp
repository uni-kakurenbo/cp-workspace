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
#define FORD(i,a,b) for(ll i=a, i##_last=ll(b); i>=i##_last; --i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

#define R$(x,r) ((x)%(r)+(r))%(r)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }


template <class T = int> struct Matrix : vector<vector<T>> {
    Matrix(size_t h, size_t w, T init = T()) : vector<vector<T>> (h, vector<T> (w, init)) {}
    inline T& operator()(size_t i, size_t j) { return (*this)[i][j]; }
};

signed main() {
    int h, w; cin >> h >> w;
    int c; cin >> c;

    Matrix<int> a(h, w);
    REP(i, h) REP(j, w) cin >> a(i,j);

    ll ans = INF64;

    auto solve = [&]() {
        Matrix<ll> dp(h+1, w+1, INF64);
        FOR(i, 1, h) FOR(j, 1, w) {
            if(chmin(dp[i][j], min(dp[i-1][j], dp[i][j-1]))) {
                dp[i][j] += c;
                chmin(ans, dp[i][j] + a[i-1][j-1]);
            };
            chmin(dp[i][j], 1LL * a[i-1][j-1]);
            debug(dp);
        }
    };

    solve();
    reverse(ALL(a));
    solve();
    REP(i, h) reverse(ALL(a[i]));
    solve();
    reverse(ALL(a));
    solve();

    cout << ans << "\n";

    return 0;
}
