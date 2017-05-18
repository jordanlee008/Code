#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("odometer.in");
  ofstream fout ("odometer.out");

  int start, end, counter = 0;
  fin >> start >> end;
  
  for (int i = start; i <= end; i++) {
    char c[] = {"0123456789"};
    string s = "";
    int r, ifake = i, digit = 0;
    while (ifake != 0) {
      r = ifake % 10;
      ifake = ifake / 10;
      s = c[r] + s;
      digit++;
    }
    cout << s << endl;

    char first = s[0];
    char second = s[1];
    int n = 0;
    if (second == first) {
    while ((s[n] == first) && (n <= digit)) {
      n++;
    }//end while
    char seconddigit = s[n];
    n++;
    while (s[n] == first) {
      n++;
    }//end while
    if (n == digit) {
      counter++;
      cout << "HAHAHA";
    }
    }//end if
    else {
      n = 1;
      while ((s[n] == second) && (n <=digit)) {
	n++;
      }//end while
      if (n == digit) {
	counter++;
	cout << "HAHAHA";
      }
    }//end while
  }//end for

  fout << counter << endl;
  
}//end main
