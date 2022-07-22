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
    string s; cin >> s;
    ll ans = 0;
    int o = count(ALL(s), 'o');
    for(char i1='0'; i1<='9'; i1++) {
        for(char i2='0'; i2<='9'; i2++) {
            for(char i3='0'; i3<='9'; i3++) {
                for(char i4='0'; i4<='9'; i4++) {
                    string str = { i1, i2, i3, i4 };
                    bool flag = true;
                    int cnt = 0;
                    FOR(j, 0, 9) {
                        if(s[j] == 'x' && str.find(j+'0') != string::npos) {
                            flag = false;
                            continue;
                        }
                        if(s[j] == 'o' && str.find(j+'0') != string::npos) ++cnt;
                    }
                    if(cnt >= o && flag) ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
