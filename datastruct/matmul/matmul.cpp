#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> VI;

long long c[1001][1001]; // k[i][j] stores the cost of multiplying the i matrices starting from index j
int m[1001][1001]; // k[i][j] stores the first matrix in the second product

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
  
  for (int i = 0; i <= n; i ++) {
    c[1][i] = 0;
    m[1][i] = i;
  }
  
  for (int i = 0; i < n - 1; i++) {
    long long di = d[i];
    long long di1 = d[i + 1];
    long long di2 = d[i + 2];
    c[2][i] = di * di1 * di2;
    m[2][i] = i + 1;
  }
  
  for (int i = 3; i <= n; i++) { // how many matrices are being multiplied together
    //    printf("i: %d\n", i);
    for (int j = 0; j <= n - i; j++) { // starting index of matrix
      //      printf("j: %d\n", j);
      long long cost = -1;
      int bestk;
      for (int k = 1; k < i; k++) { // which 2 products to multiply
	long long dj = d[j];
	long long djk = d[j + k];
	long long dji = d[j + i];
	if (c[k][j] + c[i - k][j + k] + dj*djk*dji < cost || cost == -1) {
	  bestk = k;
	  cost = c[k][j] + c[i - k][j + k] + dj*djk*dji;
	  /*	  if (cost < 0) {
	    printf("i: %7d\tj: %7d\tk: %7d\n", i, j, k);
	    printf("%10lld\t%10lld\t%10lld\t%10lld\n", c[k][j], c[i-k][j+k], dj*djk*dji, cost);
	    }*/
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

int main() {
  VI v;
  for (int i = 0; i < 6; i++) {
    if (i % 3 == 2) v.push_back(20);
    else v.push_back(10);
  }
  cout << matmul(v) << "\n";
  cout << c[v.size() - 1][0] << "\n";
  return 0;
}

