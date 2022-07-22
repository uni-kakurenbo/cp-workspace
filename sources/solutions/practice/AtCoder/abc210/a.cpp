#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, x, y; cin >> n >> a >> x >> y;
	printf("%i\n", x*min(a,n) + y*(max(n-a,0)));
    return 0;
}
