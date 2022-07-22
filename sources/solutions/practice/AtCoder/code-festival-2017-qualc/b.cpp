#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    int n; cin >> n;

    vector<int> a(n);
    REP(i, n) cin >> a[i];

    int ans = 0;
    REP(i, pow(3, n)) {
        int i2 = i;
        ll prod = 1;
        REP(j, n) {
            if(i2 % 3 == 0) {
                prod *= a[j]-1;
            } else if(i2 % 3 == 1) {
                prod *= a[j];
            } else {
                prod *= a[j]+1;
            }
            i2 /= 3;
        }
        if(prod % 2 == 0) {
            ans++;
        }
    }
    printf("%i\n", ans);
    return 0;
}
