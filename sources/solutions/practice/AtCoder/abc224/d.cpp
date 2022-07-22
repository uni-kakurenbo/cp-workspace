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

#define INF32 2147483647

signed main() {
    int m; cin >> m;

    Graph<int> G(9);
    REP(i, m) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].emplace_back(b), G[b].emplace_back(a);
    }
    debug(G);

    vector<int> p(9), q(9);
    REP(i, 8) cin >> p[i+1], q[--p[i+1]] = i+1;
    p[0] = reduce(++ALL(p), 0^1^2^3^4^5^6^7^8, [](int &a, int &b) { return a^b; });
    debug(p, q);

    queue<pair<vector<int>,vector<int>>> que;
    map<vector<int>,int> dist;

    que.emplace(p, q);
    dist[p] = 0;

    until(que.empty()) {
        auto [p,q] = que.front(); que.pop();

        bool flag = true;
        REP(i, 9) flag &= (i+1)%9 == q[i];
        if(flag) {
            cout << dist[p] << endl;
            return 0;
        }

        auto np = p, nq = q;
        int empty_pos = np[0];
        for(int next_pos : G[empty_pos]) {
            int next_type = nq[next_pos];
            swap(nq[next_pos], nq[empty_pos]); swap(np[0], np[next_type]);
            if(!dist.count(np)) {
                que.emplace(np,nq);
                dist[np] = dist[p] + 1;
            }
            swap(nq[next_pos], nq[empty_pos]); swap(np[0], np[next_type]);
        }
    }

    cout << -1 << "\n";
    return 0;
}
