/*
Jordan Lee
Bergen County Academies
Intermediate Division
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int power (int b, int p) {
  if (p == 0)
    return 1;
  int out = 1;
  for (int i = 0; i < p; i++) {
    out *= b;
  }
  return out;
}

vector<int> otob (int x) { //octal to binary
  vector<int> out(3);
  for (int i = 3; i > 0; i--) {
    int ptwo = power(2, i - 1);
    if (ptwo <= x) {
      out[i - 1] = 1;
      x -= ptwo;
    }
    else {
      out[i - 1] = 0;
    }
  }
  return out;
}

int btoo (vector<int> x) { //binary to octal
  int out = 0;
  if (x[0])
    out += 1;
  if (x[1])
    out += 2;
  if (x[2])
    out += 4;
  return out;
}

vector<int> stob (string x) { //string to binary
  vector<int> out(3);
  if (x[0] == '-')
    out[2] = 0;
  else
    out[2] = 1;
  if (x[1] == '-')
    out[1] = 0;
  else
    out[1] = 1;
  if (x[2] == '-')
    out[0] = 0;
  else
    out[0] = 1;
  return out;
}

vector<int> itob (int i) { //number to binary
  vector<int> out(3);
  if (i >= 100) {
    out[2] = 1;
    i -= 100;
  } else {
    out[2] = 0;
  }
  if (i >= 10) {
    out[1] = 1;
    i -= 10;
  } else {
    out[1] = 0;
  }
  if (i > 0) {
    out[0] = 1;
  } else {
    out[0] = 0;
  }
  return out;
}

string btos (vector<int> x) {
  string out = "";
  if (x[2]) {
    out += "r";
  } else {
    out += "-";
  }
  if (x[1]) {
    out += "w";
  } else {
    out += "-";
  }
  if (x[0]) {
    out += "x";
  } else {
    out += "-";
  }
  return out;
}

int main () {
  ifstream fin ("chmod.in");
  ofstream fout ("chmod.out");

  int l1[3];
  int l2[3];
  int l3[3];
  int l4[3];
  string l5[3];
 
  for (int i = 0; i < 3; i++)
    fin >> l1[i];
  for (int i = 0; i < 3; i++)
    fin >> l2[i];
  for (int i = 0; i < 3; i++)
    fin >> l3[i];
  for (int i = 0; i < 3; i++)
    fin >> l4[i];
  for (int i = 0; i < 3; i++)
    fin >> l5[i];
  
  fout << "1. ";
  for (int i = 0; i < 3; i++) {
    vector<int> x = otob(l1[i]);
    for (int j = 2; j >= 0; j--) {
      fout << x[j];
    }
    fout << " ";
  }
  fout << " and ";
  for (int i = 0; i < 3; i++) {
    fout << btos(otob(l1[i])) << " ";
  }
  fout << endl;
  
  fout << "2. ";
  for (int i = 0; i < 3; i++) {
    vector<int> x = otob(l2[i]);
    for (int j = 2; j >= 0; j--) {
      fout << x[j];
    }
    fout << " ";
  }
  fout << " and ";
  for (int i = 0; i < 3; i++) {
    fout << btos(otob(l2[i])) << " ";
  }
  fout << endl;
  
  fout << "3. ";
  for (int i = 0; i < 3; i++) {
    fout << btoo(itob(l3[i])) << " ";
  }
  fout << " and ";
  for (int i = 0; i < 3; i++) {
    fout << btos(itob(l3[i])) << " ";
  }
  fout << endl;
  
  fout << "4. ";
  for (int i = 0; i < 3; i++) {
    fout << btoo(itob(l4[i])) << " ";
  }
  fout << " and ";
  for (int i = 0; i < 3; i++) {
    fout << btos(itob(l4[i])) << " ";
  }
  fout << endl;
  
  fout << "5. ";
  for (int i = 0; i < 3; i++) {
    fout << btoo(stob(l5[i])) << " ";
  }
  fout << " and ";
  for (int i = 0; i < 3; i++) {
    vector<int> x = stob(l5[i]);
    for (int j = 2; j >= 0; j--) {
      fout << x[j];
    }
    fout << " ";
  }
  fout << endl;
  return 0;
}
