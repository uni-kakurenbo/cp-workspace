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
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template <class T> using Graph = vector<vector<T>>;

signed main() {
    int n, m; cin >> n >> m;
    Graph<int> A(n), B(n);
    REP(i, m) {
        int x, y; cin >> x >> y;
        --x, --y;
        A[x].emplace_back(y), A[y].emplace_back(x);
    }
    REP(i, m) {
        int x, y; cin >> x >> y;
        --x, --y;
        B[x].emplace_back(y), B[y].emplace_back(x);
    }
    debug(A, B);
    vector<int> p(n);
    iota(ALL(p), 0);
    debug(p);
    do {
        bool flag = true;
        REP(i, n) REP(j, n) {
            if(count(ALL(A[i]), j) && count(ALL(B[p[i]]), p[j]) < 1) flag = false;
        }
        if(flag) {
            debug(p);
            cout << "Yes" << "\n";
            return 0;
        }
    } while(next_permutation(ALL(p)));
    cout << "No" << "\n";
    return 0;
}
