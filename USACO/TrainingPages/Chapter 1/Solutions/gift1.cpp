/*
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findstr(string s1, string s[], int n) {
  for (int i = 0; i < n; i++) {
    if (s1 == s[i]) return i;
  }
  return -1;
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int np;
    fin >> np;

    string names[np];
    int money[np];

    for (int i = 0; i < np; i++) {
      fin >> names[i];
      money[i] = 0;
    }

    for (int i = 0; i < np; i++) {
      string giver, receiver;
      int total, nreceiver;
      fin >> giver;
      fin >> total >> nreceiver;
      int igiver = findstr(giver, names, np);
      int mrecv = 0;
      if (nreceiver > 0) {
	mrecv = total/nreceiver;
      }
      printf("%s giving: %d*%d\n", giver.c_str(), nreceiver, mrecv);
      money[igiver] -= nreceiver*mrecv;
      
      for (int j = 0; j < nreceiver; j++) {
	fin >> receiver;
	int ireceiver = findstr(receiver, names, np);
	money[ireceiver] += mrecv;
      }      
    }

    for (int i = 0; i < np; i++) {
      fout << names[i] << " " << money[i] << endl;
    }

    return 0;
}
