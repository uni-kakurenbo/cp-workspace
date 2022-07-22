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
    int n, k; cin >> n >> k;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    ll ans = 0;
    REP(i, 1LL << n) {
        vector<int> cnt(26);
        REP(j, n) {
            if((i >> j) & 1) continue;
            FORA(c, s[j]) cnt[c - 'a']++;
            ll x = 0;
            FORA(v, cnt) if(v == k) x++;
            chmax(ans, x);
        }
    }
    printf("%lli\n", ans);
    return 0;
}
