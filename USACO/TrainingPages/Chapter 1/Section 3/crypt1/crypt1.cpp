/*
ID: jorlee
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int digitCheck[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool checkDigits(int n) {
  while (n != 0) {
    int r = n % 10;
    n = n / 10;
    if (!digitCheck[r])
      return false;
  }//end while
  return true;
}//end checkDigits

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");

  int nDigits = 0, counter = 0;
  fin >> nDigits;
  int digits[nDigits];
  for (int i = 0; i < nDigits; i++) {
    fin >> digits[i];
    digitCheck[digits[i]] = 1;
  }//end for
  
  for (int i1 = 0; i1 < nDigits; i1++) {
    for (int i2 = 0; i2 < nDigits; i2++) {
      for (int i3 = 0; i3 < nDigits; i3++) {
	
	int in = 100 * digits[i1] + 10 * digits[i2] + 1 * digits[i3];
	
	for (int j1 = 0; j1 < nDigits; j1++) {
	  int xj1 = in * digits[j1];
	  if ((xj1 < 100) || (xj1 >= 1000) || (!checkDigits(xj1))) continue;
	  for (int j2 = 0; j2 < nDigits; j2++) {
	    int xj2 = in * digits[j2];
	    if ((xj2 < 100) || (xj2 >= 1000) || (!checkDigits(xj2))) continue;
	    
	    int sum = 10 * xj1 + 1 * xj2;
	    if ((sum >= 1000) && (sum < 10000) && (checkDigits(sum))) {
	      counter++;
	    }//end if
	  }//end for j2
	}//end for j1
	
      }//end for n3
    }//end for n2
  }//end for n1

  fout << counter << endl;
}//end main
