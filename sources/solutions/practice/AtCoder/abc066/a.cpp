#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

template <typename T>
using Matrix = vector<vector<T>>;

int main() {
    ll n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int parity = 0;
    deque<int> ans;
    REP(i, n) {
        if(parity == 0) ans.push_back(a[i]);
        else ans.push_front(a[i]);
        parity = ++parity % 2;
    }
    if(parity == 1) reverse(ALL(ans));
    FORA(v, ans) printf("%i\n", v);
}
