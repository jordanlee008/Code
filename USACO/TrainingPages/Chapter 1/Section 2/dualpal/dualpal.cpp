/*
ID: jorlee
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

string convert (int n, int b) {
  char c[] = {"0123456789"};
  int r;
  string s = "";
  while (n != 0) {
    r = n % b;
    n = n / b;
    s = c[r] + s;
  }//end while
  return s;
}//end convert

bool palindrome (string s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }//end if
  }//end for
  return true;
}//end palindrome

int main () {
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");

  int N, S;
  fin >> N >> S;
  int count = 0;
  int test = S + 1;
  
  while (count != N) {
    int palcount = 0;
    for (int i = 2; i <= 10; i++) {
      if (palindrome(convert(test,i)))
	palcount++;
    }//end for
    if (palcount > 1) {
      count++;
      fout << test << endl;
    }//end if
    test++;
  }//end while
}//end main
