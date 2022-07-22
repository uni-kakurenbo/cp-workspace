#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(a, b) a=max(a, b)
#define chmin(a, b) a=min(a, b)

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    k--;
    REP(i, n) {
        if(s[i] == s[k]) cout << s[k];
        else cout << '*';
    }
    cout << endl;
    return 0;
}
