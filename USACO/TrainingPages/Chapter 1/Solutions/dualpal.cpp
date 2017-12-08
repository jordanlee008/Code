/*
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string convert(int n, int b) {
  char c[] = "0123456789ABCDEFGHIJ";
  int r;
  string s("");
  
  while (n != 0) {
    r = n % b;
    n = n / b;
    s = c[r] + s;
  }
  return s;
}

int palindrome(string s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n-1-i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, s;
    fin >> n >> s;

    int ncount = 0;
    while (ncount < n) {
      s++;
      int npal = 0;
      for (int b = 2; b <= 10; b++) {
	if (palindrome(convert(s, b)))
	  npal++;
      }
      if (npal >= 2) {
	ncount++;
	fout << s << endl;
      }
    }

    return 0;
}
