#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) do { Debug::debug(nullptr, "#" + to_string(__LINE__) + ": "); Debug::debug(__VA_ARGS__); } while(0);
#else
    #define debug(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> indices(n+1);
    REP(i, n) {
        cin >> a[i];
        indices[a[i]].emplace_back(i);
    }
    debug(indices);
    int q; cin >> q;
    REP(i, q) {
        int l, r, x; cin >> l >> r >> x;
        r--, l--;
        cout << upper_bound(ALL(indices[x]), r) - lower_bound(ALL(indices[x]), l) << endl;
    }
    return 0;
}
