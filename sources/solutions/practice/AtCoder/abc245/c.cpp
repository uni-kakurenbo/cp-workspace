#include <bits/stdc++.h>
using namespace std;

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

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    vector<map<int, bool>> memo(n);
    function<bool(int,int)> dfs = [&](int i, int prev) {
        if(i >= n) return true;
        if(memo[i].count(prev)) return memo[i][prev];
        bool res = false;
        if(abs(prev-a[i]) <= k) res |= dfs(i+1, a[i]);
        if(abs(prev-b[i]) <= k) res |= dfs(i+1, b[i]);
        return memo[i][prev] = res;
    };

    cout << (dfs(0, a[0]) || dfs(0, b[0]) ? "Yes" : "No") << endl;

    return 0;
}
