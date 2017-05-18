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
  
  vector< vector<int> > drinks (M);
  //drinks[i][j] holds info about at what time the i'th drink was drank by j'th person

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      drinks[i].push_back(-1);
  
  for (int i = 0; i < D; i++) {
    int a, b, c;
    //a: person
    //b: drink
    //c: time
    fin >> a >> b >> c;
    if (drinks[b - 1][a - 1] == -1)
      drinks[b - 1][a - 1] = c - 1;
    else
      drinks[b - 1][a - 1] = min(drinks[b - 1][a - 1], c - 1);
  }

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      printf("drinks[%d][%d] = %d\n", i, j, drinks[i][j]);
  
  vector<int> sick (N);
  vector<int> sickpeople(S);
  //sick[i] = j holds info about i'th person gets sick at j time
  for (int i = 0; i < S; i++) {
    int a, b;
    //a: person
    //b: time
    fin >> a >> b;
    sickpeople[i] = a - 1;
    sick[a - 1] = b - 1;
  }

  for (int i = 0; i < S; i++)
    printf("sickpeople[%d] = %d\n", i, sickpeople[i]);

  for (int i = 0; i < N; i++)
    printf("sick[%d] = %d\n", i, sick[i]);
  
  int out = S;
  for (int i = 0; i < M; i++) {
    int count = 0;
    for (int j = 0; j < S; j++) {
      if ((drinks[i][sickpeople[j]] < sick[sickpeople[j]]) && (drinks[i][sickpeople[j]] != -1))
	count++;
    }
    if (count == S) {
      printf("drink %d is bad\n", i);
      int temp = 0;
      for (int j = 0; j < drinks[i].size(); j++)
	if (drinks[i][j] != -1)
	  temp++;
      out = max(temp, out);
    }
  }
  fout << out << endl;
  
  return 0;
}
