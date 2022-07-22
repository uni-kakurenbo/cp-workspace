#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i<int(n); i++)


int main() {
    int n; cin >> n;

    vector<int> V(n);
    map<int, int> mp;
    REP(i, n) {
        int a; cin >> a;
        V[i] = i+1-a;
        mp[a+i+1]++;
    }

    ll ans = 0;
    REP(i, n) {
        ans += mp[V[i]];
    }
    
    cout << ans << endl;
    return 0;
}
