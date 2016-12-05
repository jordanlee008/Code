#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> VI;

vector< vector<long long> > c; // k[i][j] stores the cost of multiplying the i matrices starting from index j
vector<VI> m; // k[i][j] stores the first matrix in the second product

string print(int start, int length) {
  //  printf("print(%d, %d)\n", start, length);
  if (length == 1) return "*";
  if (length == 2) return "**";
  string s = "";
  if (m[length][start] - start > 1) {
    s += "(";
    s += print(start, m[length][start] - start);
    s += ")";
  } else {
    s += print(start, m[length][start] - start);
  }

  if (length - (m[length][start] - start) > 1) {
    s += "(";
    s += print(m[length][start], length - (m[length][start] - start));
    s += ")";
  } else {
    s += print(m[length][start], length - (m[length][start] - start));
  }
  return s;
}

string matmul(const VI& d) {
  string o;
  int n = d.size() - 1; // number of matrices
  vector<long long> vl (n + 1, 0);
  for (int i = 0; i <= n; i++) c.push_back(vl);
  VI vi (n + 1, 0);
  for (int i = 0; i <= n; i++) m.push_back(vi);
  
  for (int i = 0; i <= n; i ++) {
    c[1][i] = 0;
    m[1][i] = i;
  }
  
  for (int i = 0; i < n - 1; i++) {
    c[2][i] = d[i] * d[i + 1] * d[i + 2];
    m[2][i] = i + 1;
  }
  
  for (int i = 3; i <= n; i++) { // how many matrices are being multiplied together
    for (int j = 0; j <= n - i; j++) { // starting index of matrix
      long long cost = 9223372036854775807;
      int bestk;
      for (int k = 1; k < i; k++) { // which 2 products to multiply
	if (c[k][j] + c[i - k][j + k] + d[j]*d[j + k]*d[j + i] < cost) {
	  bestk = k;
	  cost = c[k][j] + c[i - k][j + k] + d[j]*d[j + k]*d[j + i];
	}
      }
      c[i][j] = cost;
      m[i][j] = bestk + j;
      //      printf("m[%d][%d] = %d\n", i, j, m[i][j]);
    }
  }
  
  // output the string
  o = print(0, n);
  
  return o;
}

/*int main() {
  VI v;
  for (int i = 1; i < 1000; i++) v.push_back(i);
  cout << matmul(v) << "\n";
  cout << c[v.size() - 1][0] << "\n";
 return 0;
 }*/
