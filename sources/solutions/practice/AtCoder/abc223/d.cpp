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

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template <class T> using Graph = vector<vector<T>>;

template <class T> vector<T> sort_topologically(Graph<T> &G, vector<int> &in_degs) {
    vector<T> res;  priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0, n=size(in_degs); i<n; i++) if(!in_degs[i]) que.emplace(i);
    while(!que.empty()) {
        int v = que.top(); que.pop();
        for(T u : G[v]) if(!(--in_degs[u])) que.emplace(u);
        res.emplace_back(v);
    }
    return res;
}

signed main() {
    int n, m; cin >> n >> m;

    Graph<int> G(n);
    vector<int> in_degs(n);

    REP(i, m) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        ++in_degs[b];
    }

    auto sorted = sort_topologically(G, in_degs);

    if(size(sorted) < n) cout << -1;
    else FORA(v, sorted) cout << ++v << " ";
    cout << endl;

    return 0;
}
