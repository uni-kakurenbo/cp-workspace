#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void search(ll l, ll r, ll& ans) {
    if(gcd(l, r) == 1) ans = max(ans, r-l);
    else {
        search(l+1, r, ans);
        search(l, r-1, ans);
    }
}

int main() {
    ll l, r; cin >> l >> r;
    ll ans = 0;
    search(l, r, ans);
    cout << ans << endl;
    return 0;
}
