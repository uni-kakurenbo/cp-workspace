#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int n, k;

inline double L(int t) {
    return ceil(max(log2((double)k/(double)t), 0.0));
}
inline double P(int t) {
    return (1/(double)n) * pow(0.5, L(t));
}

int main() {
    cin >> n >> k;
    double ans = 0;
    FOR(i, 1, n) ans += P(i);
    printf("%.16f", ans);
}
