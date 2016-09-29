#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ifstream fin ("linearsearch.in");
  ofstream fout ("linearsearch.out");

  int search, n;
  int A[100];

  fin >> search >> n;
  for (int i = 0; i < n; i++) {
    fin >> A[i];
  }//end for

  bool check = false;
  for (int k = 0; k < n; k++) {
      if (A[k] == search) {
	check = true;
	fout << k + 1;
      }//end if
      else {
      }//end else
    }//end for
  if (!check)
    fout << "Null\n";
  else {
  }
}//end main
