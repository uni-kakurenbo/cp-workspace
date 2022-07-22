#include <bits/stdc++.h>
using namespace std;
 
int main() {
  // •Ï”a,b,c‚Étrue‚Ü‚½‚Ífalse‚ğ‘ã“ü‚µ‚ÄAtCoder‚Æo—Í‚³‚ê‚é‚æ‚¤‚É‚·‚éB
  bool a = true; // true ‚Ü‚½‚Í false
  bool b = false; // true ‚Ü‚½‚Í false
  bool c = true;  // true ‚Ü‚½‚Í false
 
  // ‚±‚±‚©‚çæ‚Í•ÏX‚µ‚È‚¢‚±‚Æ
 
  if (a) {
    cout << "At";
  }
  else {
    cout << "Yo";
  }
 
  if (!a && b) {
    cout << "Bo";
  }
  else if (!b || c) {
    cout << "Co";
  }
 
  if (a && b && c) {
    cout << "foo!";
  }
  else if (true && false) {
    cout << "yeah!";
  }
  else if (!a || c) {
    cout << "der";
  }
 
  cout << endl;
}
