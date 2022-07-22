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
#define FORD(i,a,b) for(int i=a; i>=int(b); --i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((int)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

#define INF64 9223372036854775807

signed main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b;
    REP(i, n) cin >> a[i];
    b = a;
    REP(i, k) {
        vector<ll> inds, v;
        ll j = i;
        do {
            v.emplace_back(a[j]);
            inds.emplace_back(j);
            j += k;
        } while(j < n);
        sort(ALL(inds));
        sort(ALL(v));
        REP(j, v.size()) {
            a[inds[j]] = v[j];
        }
    }
    sort(ALL(b));
    cout << (a==b?"Yes":"No") << endl;
    return 0;
}
