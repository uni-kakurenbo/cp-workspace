#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> bool chmax(T& a, T b) { a = std::max(a, b); return a < b; }
template<class T> bool chmin(T& a, T b) { a = std::min(a, b); return a > b; }

constexpr double PI = 3.14159265358979323846264338327950288;

int main() {
    double a, b, x; cin >> a >> b >> x;
    double h = x/(a*a);
    double ans;
    if(b <= h*2) {
        double t = 2*b - 2*h;
        ans = atan2(t, a);
    } else {
        double t = 2*a*h/b;
        ans = atan2(b, t);
    }
    printf("%.12f\n", ans / PI * 180);
    return 0;
}
