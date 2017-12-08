 /*
ID: jorlee
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

char originalSquare[10][10];
char transformSquare[10][10];
char rotateSquare[10][10][4];

bool check (char original[10][10][4], char transform[10][10], int square, int N) {
  int checked = 0;
  for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
      if (transform[i][j] == original[i][j][square]) {
	//cout << i << "," << j << " checks out \n";
      }//end if
      else {
	checked = 1;
      }
      if (checked == 1)
	return false;
      else {
      }
    }//end for
  }//end for
  return true;
}//end check

void rotate (char transform[10][10][4], int N) {
  for (int i = 1; i < 4; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
	transform[j][k][i] = transform[N-(k+1)][j][i-1];
	cout << transform[j][k][i];
      }//end for
      cout << "\n";
    }//end for
  }//end for
  cout << "\n";
}//end rotate

void reflect (char original[10][10], char transform[10][10][4], int N) {
  for (int j = 0; j < N; j++) {
    for (int k = 0; k < N; k++) {
      transform[j][k][0] = original[j][N-k-1];
      cout << transform[j][k][0];
    }//end for
    cout << "\n";
  }//end for
  cout << "\n";
}//end reflection

int main() {
  //open files
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");

  //get input
  int N;
  fin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> originalSquare[i][j];
      rotateSquare[i][j][0] = originalSquare[i][j];
      cout << originalSquare[i][j];
    }//end for
    cout << "\n";
  }//end for
  cout << "\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> transformSquare[i][j];
      cout << transformSquare[i][j];
    }//end for
    cout << "\n";
  }//end for
  cout << "\n";

  //check both first
  bool checkfirst = check(rotateSquare, transformSquare, 0, N);
  bool checked = false;
  rotate(rotateSquare, N);
  for (int i = 1; i < 4; i++) {
    cout << i << "\n";
    checkfirst = check(rotateSquare, transformSquare, i, N);
    if (checkfirst && (!checked)) {
      fout << i << "\n";
      checked = true;
    }
    else {
    }
  }//end for
  if (checkfirst && (!checked)) {
    fout << "6\n";
    checked = true;
  }
  else {
  }
  reflect(originalSquare, rotateSquare, N);
  checkfirst = check(rotateSquare, transformSquare, 0, N);
  if (checkfirst && (!checked)) {
    fout << "4\n";
    checked = true;
  }
  else {
  }
  rotate(rotateSquare, N);
  for (int i = 1; i < 4; i++) {
    checkfirst = check(rotateSquare, transformSquare, i, N);
    if (checkfirst && (!checked)) {
      fout << "5\n";
      checked = true;
      cout << i;
    }
    else {
    }
  }//end for
  if (!checked)
    fout << "7\n";
  else {
  }
}//end main

