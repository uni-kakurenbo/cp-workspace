/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region tmplate */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

#define INF32 2147483647
#define INF64 9223372036854775807LL

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define REPD(i,n) for(int i=(n)-1; i>=0; --i)
#define FOR(i,a,b) for(ll i=(a), i##_last=ll(b); i<=i##_last; ++i)
#define FORD(i,a,b) for(ll i=(a), i##_last=ll(b); i>=i##_last; --i)

#define ALL(x) begin((x)),end((x))
#define RALL(x) rbegin((x)),rend((x))

#define F$ first
#define S$ second

using ll = long long;
using ull = unsigned long long;
using ld = long double;

template<class T1, class T2> inline auto mod(T1 x, T2 r) { return (x%r+r)%r; }

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }
/* #endregion */

#include <atcoder/dsu>
using namespace atcoder;

using Bomb = pair<int,int>;
template <class T> using Graph = vector<vector<T>>;

signed main() {
    int n, r; cin >> n >> r;
    vector<Bomb> bombs(n);
    REP(i, n) cin >> bombs[i].F$ >> bombs[i].S$;
    string s; cin >> s;

    Graph<int> G(n);

    FOR(i, 0, n-2) FOR(j, i+1, n-1) {
        auto [xi, yi] = bombs[i];
        auto [xj, yj] = bombs[j];
        int dx = abs(xi - xj), dy = abs(yi - yj);
        if(1LL*dx*dx + 1LL*dy*dy <= 1LL*r*r) G[i].emplace_back(j), G[j].emplace_back(i);
    }

    queue<int> que;
    vector<int> exploded(n);

    REP(i, n) {
        if(s[i] == 'Y') que.emplace(i), exploded[i] = true;
    }

    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nv : G[v]) {
            if(exploded[nv]) continue;
            exploded[nv] = true;
            que.emplace(nv);
        }
    }

    cout << reduce(ALL(exploded)) << "\n";

    return 0;
}
