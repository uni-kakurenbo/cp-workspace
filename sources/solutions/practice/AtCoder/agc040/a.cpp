#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

int main() {
    string s; cin >> s;
    size_t n = s.size()+1;

    
    queue<int> que;
    vector<ll> a(n);

    if(s[0] == '<') {
        que.push(0); a[0] = 0;
    }
    REP(i, n-2) {
        if(s[i] == '>' && s[i+1] == '<') {
            que.push(i+1);
            a[i+1] = 0;
        }
    }
    if(s[n-2] == '>') {
        que.push(n-1); a[n-1] = 0;
    }

    int d[2] = {-1, 1};
    while(!que.empty()) {
        ll v = que.front(); que.pop();
        REP(i, 2) {
            ll nv = v + d[i];
            if(nv < 0 || nv >= n) continue;
            if((d[i] == -1 && s[nv] != '>') || (d[i] == 1 && s[nv-1] != '<')) continue;
            a[nv] = a[v] + 1;
            que.push(nv);
        }
    }

    ll ans = 0;
    REP(i, n) ans += a[i];
    
    cout << ans << endl;

    return 0;
}
