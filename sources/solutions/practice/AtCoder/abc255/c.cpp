#include<bits/stdc++.h>

using namespace std;

int main(){
  long long x,a,d,n;
  cin >> x >> a >> d >> n;

  if(d<0){
    long long fi=a+d*(n-1);
    a=fi;
    d*=-1;
  }

  long long st=0,fi=(n-1);
  while(st<=fi){
    long long te=(st+fi)/2;
    if((a+d*te)<x){st=te+1;}
    else{fi=te-1;}
  }
  long long res=8e18;
  for(long long i=max(0ll,st-1);i<=min((n-1),st+1);i++){
    res=min(abs(a+d*i-x),res);
  }
  cout << res << '\n';
  return 0;
}
