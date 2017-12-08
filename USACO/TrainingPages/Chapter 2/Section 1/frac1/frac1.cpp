/*
  ID: jorlee
  PROG: frac1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > frac; 
//final output list - needs to be constructed then sorted
//frac[x][0] contains numerator
//frac[x][1] contains denominator

int N; //input number (biggest denominator)

bool comparefrac(const vector<int> &a, const vector<int> &b) {
  return a[0] * b[1] < b[0] * a[1];
}

int gcd (int a, int b) { 
  //USE EUCLIDEAN ALGORITHM TO FIGURE DETERMINE GCD
  //a > b
  int r;
  do {
    r = a % b;
    a = b;
    b = r;
  } while (r != 0);
  return a;
}

void construct () {
  for (int i = 1; i <= N; i++) {
      for (int j = 1; j < i; j++) {
	vector<int> x(2); //pushed onto frac vector
	//cout << "i: " << i << " j: " << j << endl;
	if (gcd(i, j) == 1) {
	  x[0] = j;
	  x[1] = i;
	  frac.push_back(x);
	}
      }
    }
}

int main () {
  ofstream fout ("frac1.out");
  ifstream fin ("frac1.in");

  fin >> N;

  construct();
  /*  for (int i = 0; i < frac.size(); i++)
    cout << frac[i][0] << " " << frac[i][1] << endl;
  for (int i = 0; i < decimal.size(); i++)
  cout << decimal[i] << endl; */
  
  sort(frac.begin(), frac.end(), comparefrac);
  fout << "0/1\n";
  for (int i = 0; i < frac.size(); i++)
    fout << frac[i][0] << "/" << frac[i][1] << endl;
  fout << "1/1\n";
  
  return 0;
}
