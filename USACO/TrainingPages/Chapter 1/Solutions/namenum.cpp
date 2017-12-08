/*
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ttstring(string s) {
  char ttval[] = {'2', '2', '2',
		 '3', '3', '3',
		 '4', '4', '4',
		 '5', '5', '5',
		 '6', '6', '6',
		  '7', ' ', '7', '7',
		 '8', '8', '8',
		  '9', '9', '9', ' '};
  string sval("");
  for (int i = 0; i < s.length(); i++) {
    sval += ttval[s[i]-'A'];
  }
  return sval;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");

    string sin;
    fin >> sin;

    int nmatch = 0;
    while (!dict.eof()) {
      string s;
      dict >> s;
      string stt = ttstring(s);
      if (sin == stt) {
	fout << s << endl;
	nmatch++;
      }
    }

    if (nmatch == 0) {
      fout << "NONE" << endl;
    }

    return 0;
}
