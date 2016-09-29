#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ifstream fin ("insertionsort.in");
  ofstream fout ("insertionsort.out");

  int n;
  int A[100];

  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> A[i];
  }//end for

  for (int j = 1; j < n; j++) {
    int key = A[j];
    int k = j - 1;
    while ((A[k] < key) && (k >= 0)) {
      A[k + 1] = A[k];
      k = k - 1;
    }//end while
    A[k + 1] = key;
  }//end for

  for (int i = 0; i < n; i++) {
    fout << A[i];
  }//end for
}//end main
