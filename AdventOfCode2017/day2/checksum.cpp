#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin ("checksum.in");
  ofstream fout ("checksum.out") ;
  
  long int checksum = 0;

  int r,c;
  fin >> r >> c;
  vector< vector<int> > t;
  for (int i = 0; i < r; i++) {
    vector<int> v;
    //    int min = 1E18, max = 0;
    for (int j = 0; j < c; j++) {
      int x;
      fin >> x;
      v.push_back(x);
      //      if (x < min) min = x;
      //      if (x > max) max = x;
      for (int k = 0; k < j; k++) {
	if (!(v[k] % v[j])) checksum += v[k] / v[j];
	if (!(v[j] % v[k])) checksum += v[j] / v[k];
      }
    }
    t.push_back(v);
    //    checksum += max - min;
  }
  
  fout << checksum << "\n";
  
  
  return 0;
}

