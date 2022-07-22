#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

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

template <class T = int> struct Matrix : vector<vector<T>> {
    Matrix(size_t height, size_t width, T init = T()) : vector<vector<T>> (height, vector<T> (width, init)) {}
    inline T& operator()(size_t i, size_t j) {return (*this)[i][j]; }
};

using mint = modint998244353;

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    Matrix<mint> dp(n, 10);

    dp[0][a[0]] = 1;

    FOR(i, 1, n-1) {
        FOR(j, 0, 9) {
            dp[i][(j+a[i])%10] += dp[i-1][j];
            dp[i][(j*a[i])%10] += dp[i-1][j];
        }
    }

    REP(i, 10) cout << dp[n-1][i].val() << "\n";

    return 0;
}
