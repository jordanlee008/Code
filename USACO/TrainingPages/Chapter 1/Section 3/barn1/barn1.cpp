/*
ID: jorlee
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");

  int maxBoard = 0, numberOfStalls = 0, numberOfCows = 0, spaceNotUsed = 0; 
  fin >> maxBoard >> numberOfStalls >> numberOfCows;
  int stallOccupy[numberOfCows];
  int stallDifference[numberOfCows - 1];
  for (int i = 0; i < numberOfCows; i++)
    fin >> stallOccupy[i];

  for (int i = 1; i < numberOfCows; i++) {
    int key = stallOccupy[i];
    int k = i - 1;
    while ((k >= 0) && (stallOccupy[k] > key)) {
      stallOccupy[k + 1] = stallOccupy[k];
      k--;
    }//end while
    stallOccupy[k + 1] = key;
  }//end for

  int total = stallOccupy[numberOfCows - 1] - stallOccupy[0] + 1;

  for (int i = 1; i < numberOfCows; i++) {
    stallDifference[i - 1] = stallOccupy[i] - stallOccupy[i - 1] - 1;
  }//end for

  for (int i = 1; i < numberOfCows - 1; i++) {
    int key = stallDifference[i];
    int k = i - 1;
    while ((k >= 0) && (stallDifference[k] < key)) {
      stallDifference [k + 1] = stallDifference[k];
      k--;
    }//end while
    stallDifference[k + 1] = key;
  }//end for

  if (maxBoard > numberOfCows)
    maxBoard = numberOfCows;

  for (int i = 0; i < numberOfCows; i++)
    cout << stallOccupy[i] << endl;
  
  for (int i = 0; i < maxBoard - 1; i++) {
    total -= stallDifference[i];
  }//end for

  fout << total << endl;
  
}//end main
