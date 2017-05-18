/*
ID: jorlee
PROG: badmilk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
  ifstream fin ("badmilk.in");
  ofstream fout ("badmilk.out");

  int N, M, D, S;
  //N: number of people
  //M: number of milk
  //D: number of lines of drinks
  //S: number of lines of sick people
  
  fin >> N >> M >> D >> S;

  vector< vector< vector<int> > > drinks (N);
  //drinks[i][j] holds info about i'th person's drinks at time j

  vector< vector<int> > countdrinks (N);
  //what drinks each person had

  vector<int> empty;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 100; j++)
      drinks[i].push_back(empty);
  
  for (int i = 0; i < D; i++) {
    int a; //PERSON WHO DRANK
    fin >> a;
    int b; //WHAT DRINK THEY HAD
    fin >> b;
    int c; //WHAT TIME THEY DRANK
    fin >> c;
    
    drinks[a - 1][c - 1].push_back(b - 1);
    countdrinks[a - 1].push_back(b - 1);
  }

  vector<int> sickpeople; //who got sick?
  vector<int> badtime (N);
  for (int i = 0; i < S; i++) {
    int a, b;
    //PERSON WHO DRANK BAD MILK
    //WHAT TIME THEY GOT SICK
    fin >> a >> b;
    sickpeople.push_back(a - 1);
    badtime[a - 1] = b - 1;
  }
  
  vector< vector<int> > baddrinks (N);
  //baddrinks[i] holds info about the bad drinks that the i'th person had
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < badtime[i]; j++) {
      for (int k = 0; k < drinks[i][j].size(); k++) {
	baddrinks[i].push_back(drinks[i][j][k]);
      }
    }
  }

  int meds = S;
  for (int i = 0; i < M; i++) {
    int count = 0;
    for (int j = 0; j < S; j++) {
      for (int k = 0; k < baddrinks[sickpeople[j]].size(); k++) {
	if (baddrinks[sickpeople[j]][k] == i)
	  count++;
      }
    }
    if (count == S) {
      int tempmed = 0;
      for (int j = 0; j < N; j++) {
	for (int k = 0; k < countdrinks[j].size(); k++) {
	  if (countdrinks[j][k] == i)
	    tempmed++;
	}
      }
      meds = max(tempmed, meds);
    }
  }

  fout << meds << endl;
  
  return 0;
}
