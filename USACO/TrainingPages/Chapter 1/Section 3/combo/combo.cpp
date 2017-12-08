/*
ID: jorlee
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

bool validate (int test[3], int combo[3], int n) {
  for (int i = 0; i < 3; i++) {
    int z = (n + test[i] - combo[i]) % n;
    if ((z > 2) && (z < n - 2))
      return false;
  }//end for
  return true;
}//end validate

int main () {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");

  int n = 0, countvalid = 0;
  int master[3], farmer[3];
  fin >> n;
  //  cout << n << endl;
  for (int i = 0; i < 3; i++) {
    fin >> farmer[i];
    //    cout << farmer[i] << endl;
  }
  for (int i = 0; i < 3; i++) {
    fin >> master[i];
    //    cout << master[i] << endl;
  }
  
  int test[3];
  for (test[0] = 1; test[0] <= n; test[0]++) {
    for (test[1] = 1; test[1] <= n; test[1]++) {
      for (test[2] = 1; test[2] <= n; test[2]++) {
	if ((validate(test, farmer, n)) || (validate(test, master, n))) {
	  countvalid++;
	  cout << test[0] << " " << test[1] << " " << test[2] << endl;
	}//end if
      }//end for test2
    }//end for test1
  }//end for test0
  fout << countvalid << endl;
}//end main
