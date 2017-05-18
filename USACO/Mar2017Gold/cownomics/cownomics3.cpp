#include <iostream>
#include <fstream>

using namespace std;

int N, M;
string scow[500];
string pcow[500];
int length;
bool found;

int main() {
  ifstream fin ("cownomics.in");
  ofstream fout ("cownomics.out");
  
  fin >> N >> M;
  for (int i = 0; i < N; i++) fin >> scow[i];
  for (int i = 0; i < N; i++) fin >> pcow[i];
  //  for (int i = 0; i < N; i++) printf("%d\t%s\t%s\n", i, scow[i].c_str(), pcow[i].c_str());

  length = 1;
  found = false;
  
  int finallength = M + 1;
  
  int lo = 0, hi = M;
  int mid = (lo + hi) / 2;
  
  while (length < M + 1) {
    //    printf("length: %d\n", length);
    for (int i = 0; i < M - length + 1; i++) {
      //      printf("length, start: %d, %d\n", length, i + 1);
      found = true;
      for (int j = 0; j < N && found; j++) {
	for (int k = 0; k < N && found; k++) {
	  if (scow[j].substr(i, length) == pcow[k].substr(i, length)) {
	    found = false;
	    //	    printf("scow[%d], pcow[%d]\n", j, k);
	  }
	}
      }
      if (found) {
	
      }
    }
    // not found
    
  }
  
  //  fout << finallength << "\n";
  //  cout << finallength << "\n";
}
