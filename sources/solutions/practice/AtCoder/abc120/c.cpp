#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(x) x.begin(),x.end() 

int main() {
    string s; cin >> s;
    cout << min(count(ALL(s), '0'), count(ALL(s), '1'))*2 << endl;
    return 0;
}
