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

template <class T> using Graph = vector<vector<T>>;

signed main() {
    int n; cin >> n;
    vector<int> t(n);
    Graph<int> G(n);
    REP(i, n) {
        cin >> t[i];
        int k; cin >> k;
        G[i].resize(k);
        REP(j, k) cin >> G[i][j], --G[i][j];
    }
    debug(t, G);
    ll ans = 0;
    vector<bool> seen(n);
    function<void(int)> race = [&](int i) {
        if(seen[i]) return;
        seen[i] = true;
        ans += t[i];
        for(int next : G[i]) {
            race(next);
        }
    };
    race(n-1);
    cout << ans << "\n";
    return 0;
}
