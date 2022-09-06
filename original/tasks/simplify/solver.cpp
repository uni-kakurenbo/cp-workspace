#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(ll i=0, i##_length=ll(n); i<i##_length; ++i)

using PP = pair<ll, ll>;

PP solve(ll P, ll Q) {
    ll q = floor(sqrt(Q));
    if(q*q == Q) return PP (P+q, 0);
    ll D = P*P - Q, d = floor(sqrt(D));
    if(Q%4 == 0 && D >= 0LL && d*d == D) return PP ((P+d)/2, (P-d)/2);
    return PP (-1, -1);
}

signed main() {
   	ll t; cin >> t;
    REP(i, t) {
        ll p, q; cin >> p >> q;
        auto [a, b] = solve(p, q);
        if(a == -1LL) cout << -1 << endl;
        else cout << a << " " << b << endl;
    }
    return 0;
}
