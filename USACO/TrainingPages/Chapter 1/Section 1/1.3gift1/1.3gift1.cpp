/*
ID: jorlee
PROG: gift1
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findStr(string strSearch, string strArray[], int np) {
  for (int i = 0; i < np; i++) {
    if (strSearch == strArray[i]) {
      return i;
    } //end if
  } //end for
  return -1;
} //end findStr


int main() {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");

  const int npmax = 10;
  string people[npmax];
  int money[npmax];
  int np;
  fin >> np;
  printf("Reading %d names...\n", np);

  // Initialize money array:
  for (int i = 0; i < np; i++) {
    money[i] = 0;
  } //end for
  
  // Reading people names
  for (int i = 0; i < np; i++) {
      fin >> people[i];
      cout << "Read: " << people[i] << endl;
  } //end for

  string sGiver, sReceive;
  int nReceive, giftTotal, giftReceive, giftRemainder;

  for (int igive = 0; igive < np; igive++) {
    // Read giver name
    fin >> sGiver;
    int iGiver = findStr(sGiver, people, np);
    cout << "Giver: " << people[iGiver] << endl;

    // Read gift total and number of receivers
    fin >> giftTotal >> nReceive;

    money[iGiver] -= giftTotal;
    if (nReceive > 0) {
      giftReceive = giftTotal/nReceive;
      giftRemainder = giftTotal-nReceive*giftReceive;
      for (int i = 0; i < nReceive; i++) {
	fin >> sReceive;
	int iReceive = findStr(sReceive, people, np);
	money[iReceive] += giftReceive;
      }//end for
      money[iGiver] += giftRemainder;
    }//end if
  }//end for
  
  for (int i = 0; i < np; i++) {
    fout << people[i] << " " << money[i] << endl;
  }

  fin.close();
  fout.close();
  
}//end main
