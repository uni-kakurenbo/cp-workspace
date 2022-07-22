#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i<int(n); i++)

int main() {
    int n, x; cin >> n >> x;
    int sum=0;
    REP(i, n) {
        int a; cin >> a;
        if(i%2) a--;
        sum += a;
    }
    cout << (sum<=x?"Yes":"No")<< endl;
    return 0;
}
