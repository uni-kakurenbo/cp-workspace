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

int main() {
    ll l, r; cin >> l >> r;
    ll ans = 2019;
    FOR(i, l, r-1) {
        FOR(j, i+1, r) {
            chmin(ans, i*j%2019);
            if(ans == 0) { 
                printf("0\n");
                return 0;
            }
        }

    }
    printf("%lli\n", ans);
    return 0;
}
