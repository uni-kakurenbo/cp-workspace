#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/...>
// using namespace atcoder;

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "#" + to_string(__LINE__) + "  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

using ll = long long;
using ull = unsigned long long;

#define until(...) while(!(__VA_ARGS__))

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)
#define FOR(i,a,b) for(ll i=a, i##_last=ll(b); i<=i##_last; ++i)
#define FORA(i,I) for(auto& i:I)

#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)

#define F$ first
#define S$ second

template<class T> inline bool chmax(T &a, T b) { return (a<b ? a=b, true : false); }
template<class T> inline bool chmin(T &a, T b) { return (a>b ? a=b, true : false); }
int main(){
    string s,t;
    cin>>s>>t;

    //à≥èkÇµÇΩsÇ∆t
    vector<pair<int,char>> dis_s;
    vector<pair<int,char>> dis_t;


    pair<int,char> pre_s,pre_t;
    pre_s.first=1;
    pre_t.first=1;
    pre_s.second=s[0];
    pre_t.second=t[0];
    for(int i=1;i<s.size();i++){
        if(pre_s.second==s[i]){
            pre_s.first++;
        }else{
            dis_s.push_back(pre_s);
            pre_s.first=1;
            pre_s.second=s[i];
        }
        if(i==s.size()-1)
            dis_s.push_back(pre_s);
    }

    for(int i=1;i<t.size();i++){
        if(pre_t.second==t[i]){
            pre_t.first++;

        }else{
            dis_t.push_back(pre_t);
            pre_t.first=1;
            pre_t.second=t[i];
        }
        if(i==t.size()-1)
            dis_t.push_back(pre_t);
    }

    debug(dis_s, dis_t);

    if(dis_s.size()!=dis_t.size()){
        cout<<"No"<<endl;
        return 0;
    }

    for(int i=0;i<dis_s.size();i++){
        if(dis_s[i].second!=dis_t[i].second){
            cout<<"No"<<endl;
            return 0;
        }

        if(!(dis_s[i].first==dis_t[i].first||dis_s[i].first<dis_t[i].first&&dis_s[i].first>=2)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
