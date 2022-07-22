#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, a##b##_endll(b) ; i<=a##b##_end; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

template<class T>bool chmax(T &a, T &b) { if(a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, T &b) { if(b<a) { a=b; return true; } return false; }

inline ll range_sum(ll l, ll r) {
    return (r*(r+1) - l*(l-1))/2;
}

int main() {
    ll n, k; cin >> n >> k;

    vector<ll> fun(n);
    REP(i, n) cin >> fun[i];

    priority_queue<ll> atractions;
    REP(i, n) atractions.emplace(fun[i]);
    atractions.emplace(0);
    
    ll same = 1;
    ll rest = k;
    ll satisfaction = 0;
    while(true) {
        ll top = atractions.top();
        atractions.pop();
        ll next = atractions.top();
        if(rest >= (top-next)*same) {
            satisfaction += range_sum(next+1, top) * same;
            rest -= (top-next)*same;
            same++;
            if(next == 0) break;
        } else {
            satisfaction += range_sum(top-(rest/same)+1, top) * same;
            satisfaction += (top-rest/same) * (rest%same);
            break;
        }
    }
    
    cout << satisfaction << endl;
    return 0;
}
