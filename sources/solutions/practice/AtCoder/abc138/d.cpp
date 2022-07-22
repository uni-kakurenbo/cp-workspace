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

template <class T> using Graph = vector<vector<T>>;

signed main() {
    int n, q; cin >> n >> q;

    Graph<int> G(n);
    REP(i, n-1) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].emplace_back(b), G[b].emplace_back(a);
    }
    debug(G);

    vector<int> cnt(n);
    REP(i, q) {
        int p, x; cin >> p >> x;
        cnt[--p] += x;
    }
    debug(cnt);

    vector<bool> seen(n);
    vector<ll> ans(n);
    function<void(int,ll)> dfs = [&](int v, ll p_sum) {
        if(seen[v]) return;
        seen[v] = true;
        p_sum += cnt[v];
        ans[v] = p_sum;
        for(int nv : G[v]) {
            dfs(nv, p_sum);
        }
    };

    dfs(0, 0);

    REP(i, n) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
