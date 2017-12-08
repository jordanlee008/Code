/*
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nmonth = 12;
const int nday = 7;
int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int leapyear(int year) {
  if ((year % 4) == 0) {
    if ((year % 100) == 0) {
      if ((year % 400) == 0) {
	return 1;
      }
      else {
	return 0;
      }
    }
    else {
      return 1;
    }
  }
  else {
    return 0;
  }
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int n;
    fin >> n;

    int counts[7]; // Sat Sun ...
    for (int i = 0; i < 7; i++) {
      counts[i] = 0;
    }

    int iday = 1; // Dec. 31, 1899 is Sunday
    for (int year = 1900; year < 1900+n; year++) {
      for (int imonth = 0; imonth < 12; imonth++) {
	int nday = days_in_month[imonth];
	if ((imonth == 1) && (leapyear(year))) {
	  nday = 29;
	}
	    
	int i13 = (iday + 13) % 7;
	counts[i13]++;

	iday += nday;
	iday %= 7;
      }
    }

    fout << counts[0];
    for (int i = 1; i < 7; i++) {
      fout << " " << counts[i];
    }
    fout << endl;

    return 0;
}
