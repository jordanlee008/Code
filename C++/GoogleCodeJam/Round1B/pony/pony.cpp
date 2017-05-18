#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int N, Q;
    cin >> N >> Q;
    vector< vector<int> > r(N, vector<int>(N, 0));
    vector< vector<int> > h(N, vector<int>(2,0));
    vector< vector<int> > p(Q, vector<int>(2,0));

    for (int j = 0; j < N; j++) {
      cin >> h[j][0] >> h[j][1]; // 0 is distance, 1 is speed
    }
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
	cin >> r[j][k];
      }
    }
    for (int j = 0; j < Q; j++) {
      cin >> p[j][0] >> p[j][1]; // 0 is starting, 1 is ending
    }

    printf("Case #%d:", i + 1);
    for (int j = 0; j < Q; j++) {
      vector<double> xm(N, 2147483647);
      vector< vector<double> > x(N, vector<double>(N, 0)); // DYNAMIC PROGRAMMING
      vector< vector<int> > xh(N, vector<int>(N, -1));
      for (int k = 0; k < N; k++) {
	xh[k][k] = h[k][0];
      }
      for (int k = 1; k < N; k++) {
	for (int l = 0; l < k; l++) {
	  xh[k][l] = xh[k-1][l] - r[k-1][k]; // can the lth horse be used all the way to city k
	  if (xh[k][l] >= 0) {
	    x[k][l] = x[k-1][l] + (double)r[k-1][k]/h[l][1];
	    xm[k] = min(x[k][l], xm[k]);
	  }
	  if (l == k - 1) x[k][l + 1] = xm[k];
	}
      }
      
      printf(" %.9f", xm[N-1]);
    }
    cout << "\n";
    
    
  }
}
