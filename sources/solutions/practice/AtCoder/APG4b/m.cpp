#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  
  cout << "A:";
  int i = 0;
  while(i < a) {
    cout << "]";
    i++; //ƒ‹[ƒv‚Ì‚½‚Ñ‚É1‘‚â‚·
  }
  cout << endl << "B:";
  i = 0;
  while(i < b) {
    cout << "]";
    i++;
  }
  cout << endl;
}
