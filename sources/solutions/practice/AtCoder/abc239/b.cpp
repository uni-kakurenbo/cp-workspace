#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll div_floor(ll a,ll b){return a/b;}

int main() {
    ll X; cin >> X;
    if(X > 0)
        cout << fixed << div_floor(X, 10) << endl;
    else
        cout << fixed << div_floor(X-9, 10) << endl;
    return 0;
}
