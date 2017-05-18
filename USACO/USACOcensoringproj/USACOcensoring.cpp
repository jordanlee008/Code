#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string s, t;
  
  freopen("censor.in", "r", stdin);
  getline (cin, s);
  getline (cin, t);

  string::size_type i;

  i = s.find(t);
  while (i != std::string::npos) {
    s.erase(i, t.length());
    i = s.find(t);
  }
  cout << s << endl;

}//end main
