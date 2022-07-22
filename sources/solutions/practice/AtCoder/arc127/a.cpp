#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i=1; i<=n; i=i*10+1) for(ll j=1; i*j<=n; j*=10) {
        ans += min(j, n - i*j + 1);
    }
    cout << ans << endl;
    return 0;
}
