#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int rv[17575] = {0};

int ind(string r) {
  int sum = 0, pow = 1;
  for (int i = 0; i < r.length(); i++) {
    sum += (r[i] - 'a') * pow;
    pow *= 26;
  }
  return sum;
}

void incdec(string r, int n, string op) {
  if (op == "inc") {
    rv[ind(r)] += n;
  } else if (op == "dec") {
    rv[ind(r)] -= n;
  } else {
    cerr << "You passed " << op << "to incdec\n";
  }
}

bool comp(string r, int n, string op) {
  if (op == ">" && rv[ind(r)] > n) return true;
  if (op == ">=" && rv[ind(r)] >= n) return true;
  if (op == "<" && rv[ind(r)] < n) return true;
  if (op == "<=" && rv[ind(r)] <= n) return true;
  if (op == "==" && rv[ind(r)] == n) return true;
  if (op == "!=" && rv[ind(r)] != n) return true;
  return false;
}

int main() {
  ifstream fin ("register.in");
  ofstream fout ("register.out");
  
  string r1, r2, ifs, op1, op2;
  int n1, n2;
  int m = 0;
  while (fin >> r1) {
    fin >> op1 >> n1 >> ifs >> r2 >> op2 >> n2;
    if (comp(r2, n2, op2)) incdec(r1, n1, op1);
    int r1i = ind(r1);
    if (rv[r1i] > m) m = rv[r1i];
  }
  int mi = 0;
  for (int i = 0; i < 17575; i++) if (rv[i] > rv[mi]) mi = i;
  fout << rv[mi] << "\n";
  fout << m << "\n";
}
