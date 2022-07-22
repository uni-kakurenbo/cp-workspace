#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

int main() {
    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    int ans =  sum - a;
    ans =  min(ans, sum - b);
    ans =  min(ans, sum - c);
    cout << ans << endl;
    return 0;
}
