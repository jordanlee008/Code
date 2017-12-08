/*
ID: jorlee
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string numpad (string s) {
  char ttval[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', ' ', '7', '7', '8', '8', '8', '9', '9', '9', ' '};//end ttval
  string val = "";
  for (int i = 0; i < s.length(); i++) {
    val += ttval[s[i]-'A'];
  }//end for
  return val;
}//end numpad

int main () {
  ifstream fin ("namenum.in");
  ifstream dict ("dict.txt");
  ofstream fout ("namenum.out");

  string id;
  fin >> id;

  bool match = false;
  while (!dict.eof()) {
    string s;
    dict >> s;
    if (numpad(s) == id) {
      fout << s << endl;
      match = true;
    }//end if
  }//end while

  if (!match) {
    fout << "NONE\n";
  }
  else {
  }
}//end main
