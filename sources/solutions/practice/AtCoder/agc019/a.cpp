#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll q, h, s, d; cin >> q >> h >> s >> d;
    ll d1 = min(min(q*4, h*2), s);
    ll d2 = min(d1*2, d);
    ll n; cin >> n;
    cout << d2*(n/2) + n%2*d1<< endl;
    return 0;
}
