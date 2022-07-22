#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

int main() {
    string S; cin >> S;
    reverse(ALL(S));
    replace(ALL(S), '6', 'z');
    replace(ALL(S), '9', '6');
    replace(ALL(S), 'z', '9');
    cout << S << endl;
    return 0;
}
