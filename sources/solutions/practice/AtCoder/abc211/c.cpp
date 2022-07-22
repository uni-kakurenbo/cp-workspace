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

#define R$(x,r) ((x)%(r)+(r))%(r)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

using mint = modint1000000007;

template <class T = int> struct Matrix : vector<vector<T>> {
    Matrix(size_t h, size_t w, T init = T()) : vector<vector<T>> (h, vector<T> (w, init)) {}
    inline T& operator()(size_t i, size_t j) { return (*this)[i][j]; }
};

signed main() {
    string chokudai = "chokudai";
    string s; cin >> s;

    size_t n = size(s), m = size(chokudai);
    Matrix<mint> dp(n+1, m+1);

    REP(i, n) dp[i][0] = 1;

    REP(i, n) {
        REP(j, m) {
            dp[i+1][j+1] = dp[i][j+1];
            if(s[i] == chokudai[j]) dp[i+1][j+1] += dp[i][j];
        }
        debug(dp[i+1]);
    }

    cout << dp[n][m].val() << "\n";

    return 0;
}
