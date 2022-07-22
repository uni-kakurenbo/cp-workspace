#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)

int main(void){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx-sx, dy = ty-sy;

    string ans = "";

    ans += string(dy,'U');
    ans += string(dx,'R');

    ans += string(dy,'D');
    ans += string(dx,'L');

    ans += 'L';
    ans += string(dy+1,'U');
    ans += string(dx+1,'R');
    ans += 'D';

    ans += 'R';
    ans += string(dy+1,'D');
    ans += string(dx+1,'L');
    ans += 'U';

    cout << ans << endl;

    return 0;
}
