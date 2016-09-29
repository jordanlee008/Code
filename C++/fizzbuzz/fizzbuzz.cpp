#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ifstream fin ("fizzbuzz.in");
  ofstream fout ("fizzbuzz.out");

  int n;
  fin >> n;

  for (int i = 0; i < n; i++) {
    fout << i << ": ";
    if (i % 3 == 0)
      fout << "fizz";
    if (i % 5 == 0)
      fout << "buzz";
    fout << endl;
  }//end for
}//end main
