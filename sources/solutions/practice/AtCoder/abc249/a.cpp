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
    ll a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    ll c_a=0, c_b=0;
    ll d_a=0, d_b=0;
    REP(i, x) {
        c_a++; c_b++;
      	if(c_a <= a+c) {
        } else {
          c_a = 1;
        }
        if(c_a <= a) {
            d_a+=b;
        }
        if(c_b <= d+f) {
        } else {
            c_b = 1;
        }
        if(c_b <= d) {
            d_b+=e;
        }
    }
	//cout << d_a << "," << d_b << endl;
    if(d_a > d_b) {
        cout << "Takahashi" << endl;
    } else if(d_a < d_b) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}
