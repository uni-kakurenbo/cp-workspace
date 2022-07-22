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

using ll = long long;
using ull = unsigned long long;

template<class T> inline T mod(T &x, T &r) { return (x%r+r)%r; }

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

    queue<int> que;
    vector<int> parities(n, -1);

    que.emplace(0), parities[0] = 0;

    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nv : G[v]) {
            if(parities[nv] >= 0) continue;
            parities[nv] = (parities[v] + 1) % 2;
            que.emplace(nv);
        }
    }

    REP(i, q) {
        int a, b; cin >> a >> b; --a, --b;
        cout << (parities[a] == parities[b] ? "Town" : "Road") << "\n";
    }

    return 0;
}
