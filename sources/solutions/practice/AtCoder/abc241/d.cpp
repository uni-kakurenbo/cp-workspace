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
    int q; cin >> q;
    multiset<ll> st;
    REP(i, q) {
        short com; cin >> com;
        ll x; cin >> x;
        if(com == 1) st.insert(x);
        if(com == 2) {
            short k; cin >> k;
            auto found = st.upper_bound(x);
            bool flag = false;
            REP(i, k) {
                if(found == st.begin()) { flag = true; break; }
                found--;
            }
            cout << (flag ? -1 : *found) << endl;
        }
        if(com == 3) {
            short k; cin >> k;
            auto found = st.lower_bound(x);
            bool flag = found == st.end();
            if(!flag) REP(i, k-1) {
                found++;
                if(found == st.end()) { flag = true; break; }
            }
            cout << (flag ? -1 : *found) << endl;
        }
    }
    return 0;
}
