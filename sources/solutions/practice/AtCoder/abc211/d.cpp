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

template <class T> using Graph = vector<vector<T>>;
using mint = modint1000000007;

signed main() {
    int n, m; cin >> n >> m;

    Graph<int> G(n);
    REP(i, m) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].emplace_back(b), G[b].emplace_back(a);
    }

    queue<int> que;
    vector<int> dists(n, -1);
    vector<mint> cnt(n);

    que.emplace(0), dists[0] = 0, cnt[0] = 1;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nv : G[v]) {
            if(dists[nv] == dists[v] + 1) cnt[nv] += cnt[v];
            if(dists[nv] >= 0) continue;
            cnt[nv] += cnt[v];
            dists[nv] = dists[v] + 1;
            que.emplace(nv);
        }
    }

    cout << cnt[n-1].val() << "\n";

    return 0;
}
