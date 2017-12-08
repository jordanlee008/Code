/*
ID: jorlee
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

string convert (int number, int base) {
  char c[] = {"0123456789ABCDEFGHIJ"};
  string s = "";
  int r;
  while (number != 0) {
    r = number % base;
    number = number / base;
    s = c[r] + s;
  }//end while
  return s;
}//end convert

bool palindrome (string s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }//end if
  }//end for
  return true;
}//end palindrome

int main () {
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");

  int base;
  char base200[10];
  
  fin >> base;
  cout << base << endl;

  for (int i = 1; i <= 300; i++) {
    int isquare = i*i;
    string baseisquare = convert(isquare, base);
    if (palindrome(baseisquare)) {
      fout << convert(i, base) << " " << baseisquare << endl;
    }
  }//end for
}//end main
