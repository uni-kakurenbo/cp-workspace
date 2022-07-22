#include <bits/stdc++.h>
using namespace std;

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
#define REPD(i,n) for(int i=n-1; i>=0; --i)
#define FOR(i,a,b) for(int i=a, i##_last=int(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

signed main() {
    ll n, x; cin >> n >> x;
    string s, coms; cin >> s;
    int cnt=0;
    REPD(i, n) {
        if(s[i] == 'U') cnt++;
        else {
            if(cnt > 0) cnt--;
            else coms += s[i];
        }
    }
    REP(i, cnt) coms += 'U';
    reverse(ALL(coms));
    debug(coms);
    ll now = x;
    FORA(com, coms) {
        if(com == 'U') now /= 2;
        if(com == 'L') now *= 2;
        if(com == 'R') now = now*2 + 1;
    }

    printf("%lli\n", now);
    return 0;
}
