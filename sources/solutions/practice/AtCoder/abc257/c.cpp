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

signed main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<int,bool>> v;
    REP(i, n) {
        int w; cin >> w;
        v.emplace_back(w, s[i]-'0');
    }
    sort(ALL(v));
    debug(v);
    int sc = 0;
    REP(i, n) sc += v[i].second;
    debug(sc);
    int ans = sc;
    REP(i, n) {
        sc += v[i].second ? -1 : 1;
        while(i+1 < n && v[i+1].first == v[i].first) {
            i++;
            sc += v[i].second ? -1 : 1;
        }
        debug(sc);
        chmax(ans, sc);
    }
    cout << ans << endl;
    return 0;
}
