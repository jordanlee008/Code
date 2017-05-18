#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;
int f[2][1000];
int dp[1000][1000][2];

int main() {
  ifstream fin ("nocross.in");
  ofstream fout ("nocross.out");
  fin >> n;
  for (int i = 0; i < n; i++) fin >> f[0][i];
  for (int j = 0; j < n; j++) fin >> f[1][j];
  
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0) {
	if (f[0][i] - f[1][j] < 5 && f[0][i] - f[1][j] > -5) {
	  dp[i][j][0] = 1;
	  dp[i][j][1] = j;
	  printf("dp[%d][%d] = %d\n", i, j, dp[i][j][0]);
	} else {
	  dp[i][j][0] = 0;
	  dp[i][j][1] = -1;
	  printf("dp[%d][%d] = %d\n", i, j, dp[i][j][0]);
	}
      } else {
	if (f[0][i] - f[1][j] < 5 && f[0][i] - f[1][j] > -5) {
	  dp[i][j][0] = max(dp[i - 1][j][0] + (dp[i - 1][j][1] < j ? 1 : 0), dp[i - 1][j - 1][0] + 1);
	  dp[i][j][1] = j;
	  printf("dp[%d][%d] = %d\n", i, j, dp[i][j][0]);
	} else {
	  if (dp[i - 1][j][0] > dp[i][j - 1][0]) {
	    dp[i][j][0] = dp[i - 1][j][0];
	    dp[i][j][1] = dp[i - 1][j][1];
	    printf("dp[%d][%d] = %d\n", i, j, dp[i][j][0]);
	  } else if (dp[i - 1][j][0] < dp[i][j - 1][0]) {
	    dp[i][j][0] = dp[i][j - 1][0];
	    dp[i][j][1] = dp[i][j - 1][1];
	    printf("dp[%d][%d] = %d\n", i, j, dp[i][j][0]);
	  } else {
	    dp[i][j][0] = dp[i][j - 1][0];
	    dp[i][j][1] = min(dp[i][j - 1][1], dp[i - 1][j][1]);
	    printf("dp[%d][%d] = %d\n", i, j, dp[i][j][0]);
	  }
	}
      }
    }
  }
  int m = dp[n - 1][n - 1][0];
  cout << m << "\n";
  fout << m << "\n";
}
