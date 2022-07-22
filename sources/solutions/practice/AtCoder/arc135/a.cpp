#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define MOD 998244353
#define INV2 499122177


unordered_map<ll, ll> MEMO;
ll search(ll x) {
    if(MEMO.count(x)) return MEMO[x];
    auto& res = MEMO[x];
    if(x <= 4) return (res = x);
    else return (res = search((x+1)/2) * search(x/2) % MOD);
}

int main() {
    ll X; cin >> X;
    ll ans = search(X) % MOD;
    
    cout << ans << endl;
    return 0;
}
