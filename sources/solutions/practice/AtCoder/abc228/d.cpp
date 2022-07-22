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

signed main() {
    int n = 1LL << 20;
    int q; cin >> q;
    vector<ll> a(n, -1), last(n, -1);
    REP(i, q) {
        ll t, x; cin >> t >> x;
        debug(t, x);
        if(t == 1) {
            function<ll(ll)> merge = [&](ll pos) {
                if(last[pos%n] >= 0) {
                    return last[pos%n] = merge(last[pos%n]);
                }
                if(a[pos%n] == -1) {
                    a[pos%n] = x;
                    return pos;
                }
                return last[pos%n] = merge(pos+1);
            };
            merge(x);
        }
        if(t == 2) {
            cout << a[x%n] << "\n";
        }
    }
    return 0;
}
