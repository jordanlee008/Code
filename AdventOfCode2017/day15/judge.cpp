#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> mult(vector<int> x, vector<int> y) {
  vector<int> v(16,0);
  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j < y.size(); j++) {
      if (i+j >= 16) break;
      v[i+j] += x[i] * y[j];
    }
  }
  
  for (int i = 0; i < v.size()-1; i++) { // v[0] least sig
    v[i+1] += v[i] / 2;
    v[i] = v[i] % 2;
  }
  v[15] = v[15] % 2;
  return v;
}

vector<int> conv(int n) {
  vector<int> v;
  while (n) {
    v.push_back(n%2);
    n /= 2;
  }

  for (int i = v.size(); i < 32; i++) { v.push_back(0); }
  
  return v;
}

int inv(vector<int> v) {
  int n = 0, pow = 1;
  for (int i = 0; i < v.size() && i < 16; i++) {
    n += pow*v[i];
    pow *= 2;
  }
  return n;
}

int main() {
  ifstream fin ("judge.in");
  ofstream fout ("judge.out");

  vector<long long> a;
  vector<long long > b;

  int a0, b0;
  fin >> a0 >> b0;
  a.push_back(a0);
  b.push_back(b0);
  
  int count = 0, ai = 0, bi = 0;
  for (int i = 0; i < 5000000; i++) {
    if (i % 1000000 == 0) cout << i/1000000 << "\n";
    
    while (a[ai] % 4 != 0) {      
      a.push_back((16807 * a[ai]) % 2147483647);
      ai++;
    }
    while (b[bi] % 8 != 0) {
      b.push_back((48271 * b[bi]) % 2147483647);
      bi++;
    }
    
    vector<int> a1 = conv(a[ai]), b1 = conv(b[bi]);
    bool match = true;
    for (int j = 0; j < 16; j++) {
      if (a1[j] != b1[j]) {
	match = false;
	break;
      }
    }
    if (match) count++;
    
    a.push_back((16807 * a[ai]) % 2147483647);
    ai++;
    b.push_back((48271 * b[bi]) % 2147483647);
    bi++;
  }
  
  
  
  fout << count << "\n";
}
