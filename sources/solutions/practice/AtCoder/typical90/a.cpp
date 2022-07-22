#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

int main() {
    int n; cin >> n;
    set<string> users;
    vector<int> ans;
    REP(i, n) {
        string s; cin >> s;
        size_t size = users.size();
        users.insert(s);
        if(size == users.size()) continue;
        ans.emplace_back(i+1);
    }
    FORA(v, ans) printf("%i\n", v);
    return 0;
}
