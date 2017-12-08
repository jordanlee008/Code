/*
ID: jorlee
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int letterNumber(char input) {
  switch ( input ) {
  case 'A':
    return 1;
  case 'B':
    return 2;
  case 'C':
    return 3;
  case 'D':
    return 4;
  case 'E':
    return 5;
  case 'F':
    return 6;
  case 'G':
    return 7;
  case 'H':
    return 8;
  case 'I':
    return 9;
  case 'J':
    return 10;
  case 'K':
    return 11;
  case 'L':
    return 12;
  case 'M':
    return 13;
  case 'N':
    return 14;
  case 'O':
    return 15;
  case 'P':
    return 16;
  case 'Q':
    return 17;
  case 'R':
    return 18;
  case 'S':
    return 19;
  case 'T':
    return 20;
  case 'U':
    return 21;
  case 'V':
    return 22;
  case 'W':
    return 23;
  case 'X':
    return 24;
  case 'Y':
    return 25;
  case 'Z':
    return 26;
  default:
    return 0;
  }//end switch
}//end letterNumber

int findNameNumber(string input) {
  char inputArray[input.length()];
  int product = 1;
  for (int i = 0; i < input.length(); i++) {
    inputArray[i] = input[i];
  }//end for
  for (int i = 0; i < input.length(); i++) {
    product = product * letterNumber(inputArray[i]);
  }//end for
  return product;
}//end findNameNumber

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string comet,group;
  fin >> comet >> group;
  if (findNameNumber(comet)%47 == findNameNumber(group)%47) {
    fout << "GO" << endl;
  }//end if
  else {
    fout << "STAY" << endl;
  }//end else
  return 0;
}//end main
