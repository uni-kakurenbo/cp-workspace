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

template<class T> vector<T> divisors(T n) {
    vector<T> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) res.emplace_back(n / i);
        }
    }
    sort(ALL(res));
    return res;
}

signed main() {
    int n; cin >> n;
    int ans = 0;
    FOR(i, 1, n) {
        if(i%2 == 0) continue;
        vector divs = divisors(i);
        ans += divs.size() == 8;
    }
    printf("%i\n", ans);
    return 0;
}
