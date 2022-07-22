#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)

int main() {
    ll N; cin >> N;
    set<ll> A;
    REP(i, N) {
        ll x; cin >> x;
        A.insert(x);
    }
    cout << A.size() << endl;
    return 0;
}
