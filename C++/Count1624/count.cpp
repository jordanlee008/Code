#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("count.in");
  ofstream fout ("count.out");

  int N_max = 0;
  cin >> N_max;

  for (int N = 13; N < N_max; N++) {
    int count=0, a, b, c, d;
    int case1=0, case2=0;
    fout << N << "\n";
    for (a = 1; a < 8; a++) {
      b = 16 - a;
      if (b > N) continue;
      
      for (c = 1; c <= N; c++) {
	if (c == a || c == b) continue;
	for (d = c + 1; d <= N; d++) {
	  if (d == a || d == b) continue;
	  if (c+d==24) {
	    // case 1
	    // printf("%d %d %d %d\n",a,b,c,d);
	    count++;
	    case1++;
	  }
	  if (a+c==24 || a+d==24 || b+c==24 || b+d==24) {
	    if (c+d == 16 && c>a) continue;
	    // case 2
	    // printf("%d %d %d %d\n",a,b,c,d);
	    count++;
	    case2++;
	  }
	}
      }
    }
  
    fout << count << "\n";
    fout << case1 << " " << case2 << "\n\n";
  }
}
