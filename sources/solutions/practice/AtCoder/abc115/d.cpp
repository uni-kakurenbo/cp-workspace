#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

vector<ll> patties(100), thickness(100);
ll count_patties(ll level, ll x) {
    if(level == 0) return 1;
 
    if(x < 1) return 0;
    x--;
 
    if(x < thickness[level-1])
        return count_patties(level-1, x);
    x -= thickness[level-1];
 
    if(x < 1) return patties[level-1] + 1;
    x--;
 
    if(x < thickness[level-1])
        return patties[level-1] + 1 + count_patties(level-1, x);
    x -= thickness[level-1];
 
    return patties[level-1]*2 + 1;
}

int main() {
    ll n, x ; cin >> n >> x;
    x--;
 
    thickness[0] = 1, patties[0] = 1;
    FOR(i, 1, n) thickness[i] = thickness[i-1]*2 + 3;
    FOR(i, 1, n) patties[i] = patties[i-1]*2 + 1;
 
    printf("%lli\n", count_patties(n, x));
}
