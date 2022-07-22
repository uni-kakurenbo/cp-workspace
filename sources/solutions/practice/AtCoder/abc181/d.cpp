#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using ll = long long;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,a,b) for(ll i=a; i<=ll(b); i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()

#define chmax(t, c) t = max(t, c)
#define chmin(t, c) t = min(t, c)


int main() {
    int now = 0;
    vector<string> multiples8;
    while(now < 1000) {
        if(now % 8 == 0) {
            ostringstream sout;
            sout << setfill('0') << setw(3) << now;
            multiples8.emplace_back(sout.str());
        }
        ++now;
    }
    size_t q = multiples8.size();

    
    string s; cin >> s;
    
    if(s.size() <= 2) {
        if(s.size() == 1) s[1] = '0';
        string a({ s[0], s[1] });
        string b({ s[1], s[0] });
        if(stoi(a)%8 == 0 || stoi(b)%8 == 0) {
            printf("Yes\n");
            return 0;
        }
    }

    REP(i, q) {
        map<char, int> cnt;
        int u = multiples8[i].size();
        REP(j, u) {
            cnt[multiples8[i][j]]++;
        }
        bool flag = true;
        for(auto [k, v] : cnt) {
            if(count(ALL(s), k) < v) { flag = false; break; }
        }
        if(flag) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
