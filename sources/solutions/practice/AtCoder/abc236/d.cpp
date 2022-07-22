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

template <class T = int> struct Matrix : vector<vector<T>> {
    Matrix(size_t height, size_t width) : vector<vector<T>> (height, vector<T> (width)) {}
    Matrix(size_t height, size_t width, T init) : vector<vector<T>> (height, vector<T> (width, init)) {}
};

signed main() {
    int n; cin >> n;
    Matrix a(2*n, 2*n);
    REP(i, 2*n-1) {
        FOR(j, i+1, 2*n-1) {
            cin >> a[i][j];
       }
    }
    debug(n, a);
    int ans = -1;
    function<void(vector<bool>,int,int,int)> dfs = [&](vector<bool> used, int prev, int pos, int sc) {
        used[prev] = true;
        if(pos >= 2*n-1) chmax(ans, sc);
        FOR(i, pos%2 ? 0 : prev, 2*n-1) {
            if(used[i]) continue;
            debug(pos, used, prev, i, a[prev][i], sc);
            if(sc < 0) dfs(used, i, pos+1, a[prev][i]);
            else if(pos%2) dfs(used, i, pos+1, sc);
            else dfs(used, i, pos+1, sc^a[prev][i]);
            if(pos%2) break;
        }
        return;
    };
    dfs(vector<bool> (2*n, false), 0, 0, -1);
    cout << ans << endl;
    return 0;
}
