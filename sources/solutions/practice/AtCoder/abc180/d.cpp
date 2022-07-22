#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    ll x, y, a, b; cin >> x >> y >> a >> b;
    ll ex = 0;
    if(x != 0) {
        while(x < (x+b)/a) {
            x *= a;
            if(x >= y) {
                printf("%lli\n", ex);
                return 0;
            }
            ex++;
        }
    }
    ex += (y-x-1)/b;
    printf("%lli\n", ex);
    return 0;
}
