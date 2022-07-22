#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i<int(n); i++)

int main() {
    int n; cin >> n;
    int x = 0, y = 0;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    int d = 0;
    REP(i, n) {
        char t; cin >> t;
        if(t == 'S') {
            x += dx[d%4], y += dy[d%4];
        } else {
            d++;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}
