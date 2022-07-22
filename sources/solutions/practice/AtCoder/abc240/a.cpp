#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;
    if(b-a == 1) cout << "Yes";
    else if(a == 1 && b == 10) cout << "Yes";
    else cout << "No" << endl;
    cout << endl;
    return 0;
}
