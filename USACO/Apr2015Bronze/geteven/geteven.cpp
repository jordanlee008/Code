#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream fout ("geteven.out");
  ifstream fin ("geteven.in");

  int B[20];
  int E[20];
  int S[20];
  int I[20];
  int G[20];
  int O[20];
  int M[20];
  int b, e, s, i, g, o, m, N;
  b = 0;
  e = 0;
  s = 0;
  i = 0;
  g = 0;
  o = 0;
  m = 0;
  char variable;
  
  fin >> N;
  cout << N;
  for (int x = 0; x < N; x++) {
    fin >> variable;
    if (variable == 'B') {
      fin >> B[b];
      b++;
      cout << "Updated B as " << B[b-1] << "\n";
      cout << "b: " << b << "\n";
    }
    else if (variable == 'E') {
      fin >> E[e];
      e++;
      cout << "Updated E as " << E[e-1] << "\n";
      cout << "e: " << e << "\n";
    }
    else if (variable == 'S') {
      fin >> S[s];
      s++;
      cout << "Updated S as " << S[s-1] << "\n";
      cout << "s: " << s << "\n";
    }
    else if (variable == 'I') {
      fin >> I[i];
      i++;
      cout << "Updated I as " << I[i-1] << "\n";
      cout << "i: " << i << "\n";
    }
    else if (variable == 'G') {
      fin >> G[g];
      g++;
      cout << "Updated G as " << G[g-1] << "\n";
      cout << "g: " << g << "\n";
    }
    else if (variable == 'O') {
      fin >> O[o];
      o++;
      cout << "Updated O as " << O[o-1] << "\n";
      cout << "o: " << o << "\n";
    }
    else if (variable == 'M') {
      fin >> M[m];
      m++;
      cout << "Updated M as " << M[m-1] << "\n";
      cout << "m: " << m << "\n";
    }
    else {
      cout << "what is going on \n";
      }
  }//end for

  int counter = 0;
  int bessieOdd = 0;
  int mooOdd = 0;
  int mooEven = 0;
  int bessieEven = 0;
  int goesEven = 0;
  
  //find mooEven
  for (int mx = 0; mx < m; mx++) {
    if (M[mx]%2 == 0) {
      mooEven++;
    }
    else {
    }
  }//end
  mooOdd = m - mooEven;
  cout << "mooEven, mooOdd " << mooEven << " " << mooOdd << "\n";
  
  //find bessieEven
  for (int bx = 0; bx < b; bx++) {
    for (int ix = 0; ix < i; ix++) {
	  if ((B[bx] + I[ix])%2 == 0) {
	    bessieEven++;
	  }//end if
	  else {
	  }
    }//end loop i
  }//end loop b
  bessieOdd = b*i - bessieEven;
  cout << "bessieEven, bessieOdd " << bessieEven << " " << bessieOdd << "\n";

  //find goesEven
  for (int gx = 0; gx < g; gx++) {
    for (int ox = 0; ox < o; ox++) {
      for (int ex = 0; ex < e; ex++) {
	for (int sx = 0; sx < s; sx++) {
	  if ((G[gx] + O[ox] + E[ex] + S[sx])%2 == 0) {
	    goesEven++;
	  }
	  else {
	  }
	}//end loop s
      }//end loop e
    }//end loop o
  }//end loop g
  cout << "goesEven " << goesEven << "\n";
  counter = mooEven*b*e*s*i*g*o + mooOdd*bessieEven*e*s*g*o + mooOdd*bessieOdd*goesEven;
  cout << counter; 
  fout << counter;
}//end main
