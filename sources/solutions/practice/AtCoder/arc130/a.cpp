#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/...>
// using namespace atcoder;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define INF32 2147483647
#define INF64 9223372036854775807LL

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

template<class I, class T = typename iterator_traits<I>::value_type, class L = int, class C = vector<pair<T,L>>> struct RLE : C {
    RLE(I first, I last) {
        this->clear();
        L cnt=0;;
        for(I itr=first, prev=itr; itr!=last; itr++) {
            if(*prev != *itr) this->emplace_back(*prev, cnt), cnt = 1;
            else cnt++;
            prev = itr;
        }
        this->emplace_back(*prev(last), cnt);
    }
};

signed main() {
    int n; cin >> n;
    string s; cin >> s;
    RLE rle(ALL(s));
    ll ans = 0;
    for(auto [c, l] : rle) {
        ans += 1LL * l*(l-1)/2;
    }
    cout << ans << "\n";
    return 0;
}
