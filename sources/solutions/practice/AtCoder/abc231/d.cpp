#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

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
    int n, m; cin >> n >> m;
    dsu uf(n);
    vector<int> cnt(n);
    REP(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        if(uf.same(a, b) || cnt[a] > 1 || cnt[b] > 1) {
            cout << "No" << endl;
            return 0;
        }
        cnt[a]++, cnt[b]++;
        uf.merge(a, b);
    }
    cout << "Yes" << "\n";
    return 0;
}
