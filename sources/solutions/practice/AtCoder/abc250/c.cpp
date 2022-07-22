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
    ll n, q; cin >> n >> q;
    vector<int> a(n), inds(n);
    iota(ALL(a), 0), iota(ALL(inds), 0);
    REP(i, q) {
        ll x; cin >> x;
        x--;
        if(inds[x]+1 < n) swap(a[inds[x]], a[inds[x]+1]);
        else swap(a[inds[x]], a[inds[x]-1]);
        swap(inds[x], inds[a[inds[x]]]);
    }
    FORA(v, a) printf("%i ", ++v);
    cout << endl;
    return 0;
}
