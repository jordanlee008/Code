 /*
ID: jorlee
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");

  int nfarmer = 0;
  int farmerStart[5000];
  int farmerEnd[5000];
  int time[1000000];
  int earlyStart = 1000001;
  int lateEnd = -1;

  for (int i = 0; i < 5000; i++) {
    farmerStart[i] = 0;
    farmerEnd[i] = 0;
  }//end for

  for (int i = 0; i < 1000000; i++) {
    time[i] = 0;
  }//end for

  fin >> nfarmer;
  //  fout << "Read " << nfarmer << " farmers \n";
  for (int i = 0; i < nfarmer; i++) {
    fin >> farmerStart[i];
    fin >> farmerEnd[i];
    for (int j = farmerStart[i]; j < farmerEnd[i]; j++) {
      time[j] = 1;
      //      fout << j << " ";
    }//end for
    //    fout << "Read " << farmerStart[i] << farmerEnd[i] << "\n";
  }//end for

  for (int i = 0; i < nfarmer; i++) {
    if (earlyStart > farmerStart[i])
      earlyStart = farmerStart[i];
    if (lateEnd < farmerEnd[i])
      lateEnd = farmerEnd[i];
  }//end for
  cout << earlyStart << " " << lateEnd << "\n";

  int maxTime = 0;
  for (int i = 0; i < nfarmer; i++) {
    int c = 0;
    while (time[farmerStart[i] + c] == 1)
      c++;
    //    fout << c << "\n";
    maxTime = max(maxTime, c);
  }//end for
  fout << maxTime << " ";
  
  int maxRest = 0;
  for (int i = 0; i < nfarmer; i++) {
    int d = 0;
    while (time[farmerEnd[i] + d] != 1)
      d++;
    cout << d << "\n";
    if (farmerEnd[i] != lateEnd) {
      maxRest = max(maxRest, d);
    }
    else {
      
    }
  }//end for
  fout << maxRest << "\n";
}//end main
