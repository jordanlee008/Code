/*
ID: jorlee
PROG: friday
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLeapYear(int input) {
  if (input%4 == 0) {
    if (input%100 != 0 || input%400 == 0) {
      return true;
    }//end if
    else {
      return false;
    }
  }//end if
  return false;
}//end isLeapYear

int main() {
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");
  int n;
  fin >> n;
  int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = 0;
  int dayOfWeek = 0; //start with saturday
  int day13[7] = {0, 0, 0, 0, 0, 0, 0}; //start with saturday
  for (int i = 1900; i <= 1899 + n; i++) {
    if (isLeapYear(i)) {
      dayOfMonth[1] = 29;
      for (int j = 0; j < 12; j++) {
	day13[dayOfWeek]++;
	days = days + dayOfMonth[j];
	dayOfWeek = days%7;
      }//end for
    }//end if
    else {
      dayOfMonth[1] = 28;
      for (int j = 0; j < 12; j++) { 
	day13[dayOfWeek]++;
	days = days + dayOfMonth[j];
	dayOfWeek = days%7;
      }//end for
    }//end else
  }//end for

  fout << day13[0] << " " << day13[1] << " " << day13 [2] << " " << day13[3];
  fout << " " << day13[4] << " " << day13[5] <<  " " << day13[6]<<"\n";
    fin.close();
  fout.close();
}//end main

