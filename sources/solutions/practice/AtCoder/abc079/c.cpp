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
    char c[4]; int a[4];
    REP(i, 4) cin >> c[i];
    REP(i, 4) a[i] = c[i] - '0';
    REP(bits, 1 << 3) {
        ll res = a[0];
        vector<char> opes;
        REP(i, 3) {
            if(bits >> i & 1) {
                res += a[i+1];
                opes.emplace_back('+');
            } else {
                res -= a[i+1];
                opes.emplace_back('-');
            }
        }
        opes.emplace_back('=');
        if(res == 7) {
            REP(i, 4) {
                printf("%i%c", a[i], opes[i]);
            }
            printf("7\n");
            return 0;
        }
    }
    
    return 0;
}
