#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/...>
// using namespace atcoder;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "#" + to_string(__LINE__) + "  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m"); } while(0);
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

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int n; cin >> n;
    using Position = pair<int,int>;
    vector<Position> points(n);
    REP(i, n) cin >> points[i].first >> points[i].second;
    auto has_same_gradient = [&](int i1, int j1, int i2, int j2) {
        int dx1 = points[i1].first - points[j1].first,
            dy1 = points[i1].second - points[j1].second,
            dx2 = points[i2].first - points[j2].first,
            dy2 = points[i2].second - points[j2].second;
        return dx1*dy2 == dx2*dy1;
    };
    int ans = 0;
    FOR(i, 0, n-3) FOR(j, i+1, n-2) FOR(k, j+1, n-1) {
        ans += !has_same_gradient(i,j,j,k);
    }
    cout << ans << "\n";
    return 0;
}
