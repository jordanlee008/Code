/*
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nmax = 10;

int equivalent(int n, char in[][nmax], char out[][nmax]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (in[i][j] != out[i][j])
	return 0;
    }
  }
  return 1;
}

int rot90(int n, char in[][nmax], char out[][nmax]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      out[j][n-1-i] = in[i][j];
    }
  }
  return 1;
}

int reflect(int n, char in[][nmax], char out[][nmax]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      out[i][n-1-j] = in[i][j];
    }
  }
  return 1;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int n;
    fin >> n;

    char in[nmax][nmax], out[nmax][nmax];

    for (int i = 0; i < n; i++) {
      fin >> in[i];
    }

    for (int i = 0; i < n; i++) {
      fin >> out[i];
    }

    for (int i = 0; i < n; i++) {
      printf("%c%c%c\n", in[i][0], in[i][1], in[i][2]);
    }

    char r90[nmax][nmax], r180[nmax][nmax], r270[nmax][nmax], refl[nmax][nmax];
    rot90(n, in, r90);
    if (equivalent(n, out, r90)) {
      fout << 1 << endl;
      return 0;
    }
    rot90(n, r90, r180);
    if (equivalent(n, out, r180)) {
      fout << 2 << endl;
      return 0;
    }
    rot90(n, r180, r270);
    if (equivalent(n, out, r270)) {
      fout << 3 << endl;
      return 0;
    }
    reflect(n, in, refl);
    if (equivalent(n, out, refl)) {
      fout << 4 << endl;
      return 0;
    }
    rot90(n, refl, r90);
    if (equivalent(n, out, r90)) {
      fout << 5 << endl;
      return 0;
    }
    rot90(n, r90, r180);
    if (equivalent(n, out, r180)) {
      fout << 5 << endl;
      return 0;
    }
    rot90(n, r180, r270);
    if (equivalent(n, out, r270)) {
      fout << 5 << endl;
      return 0;
    }
    if (equivalent(n, out, in)) {
      fout << 6 << endl;
      return 0;
    }
    
    fout << 7 << endl;
    return 0;
}
