#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0, i##_len=ll(n); i<i##_len; i++)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; i++)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) x.begin(),x.end()
#define SIZE(x) ((ll)(x).size())

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }

int main() {
    vector<int> nums(3);
    REP(i, 3) cin >> nums[i];
    sort(ALL(nums));
    int ans = (nums[2]-nums[1])/2 + (nums[2]-nums[0])/2;
    if((nums[2]-nums[1])%2 == 0 && (nums[2]-nums[0])%2 == 0) {
    } else if((nums[2]-nums[1])%2 == 1 && (nums[2]-nums[0])%2 == 1) {
        ans += 1;
    } else {
        ans += 2;
    }
    printf("%i\n", ans);
    return 0;
}
