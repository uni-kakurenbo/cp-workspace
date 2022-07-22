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

template <class T = int> struct UnfoldedMatrix : vector<T> {
    UnfoldedMatrix(size_t h = 0, size_t w = 0, T init = T()) : vector<T> (h*w, init), height(h), width(w), buffer_size(h*w) {};
    inline T& operator()(size_t i, size_t j) { return (*this)[i*width+j]; }
  private:
    size_t height, width, buffer_size;
};

signed main() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];

    vector<UnfoldedMatrix<long>> dp(n+1, {x+1, y+1, INF32});

    dp[0](0,0) = 0;
    FOR(i, 1, n) {
        FOR(s, 0, x) FOR(t, 0, y) {
            chmin(dp[i](s,t), dp[i-1](s,t));
            long p = dp[i-1](max(s-a[i-1], 0LL), max(t-b[i-1], 0LL));
            chmin(dp[i](s,t), p+1);
        }
    }

    long ans = dp[n](x,y);
    cout << (ans >= INF32 ? -1 : ans) << "\n";

    return 0;
}
