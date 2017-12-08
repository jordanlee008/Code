/*
PROG: palsquare
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
    //    s += c[r];
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int b;
    fin >> b;

    int n, nsq;
    for (n = 1; n <= 300; n++) {
      nsq = n*n;
      string s = convert(nsq, b);
      if (palindrome(s)) {
	fout << convert(n,b) << " " << s << endl;
      }
    }

    return 0;
}
