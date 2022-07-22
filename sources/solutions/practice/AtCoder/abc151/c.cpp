#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i<int(n); i++)

int main() {
    int n, m; cin >> n >> m;

    using Result = pair<ll, bool>;
    map<int, Result> problems;

    int ac_count = 0; ll penalty_sum = 0;
    REP(i, m) {
        int p; string s;
        cin >> p >> s;
        if(s == "AC") {
            if(!problems[p].second) {
                penalty_sum += problems[p].first;
                ac_count++;
                problems[p].second = true;
            }
        } else {
            if(!problems[p].second) problems[p].first++;
        }
    }
    cout << ac_count << " ";
    cout << penalty_sum << endl;
    return 0;
}
