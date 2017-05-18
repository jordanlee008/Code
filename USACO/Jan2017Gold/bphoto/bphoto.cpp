#include <iostream>
#include <fstream>

using namespace std;

int n, big;
int h[100000];
int l[100000];
int r[100000];

int main() {
  ifstream fin ("bphoto.in");
  ofstream fout ("bphoto.out");

  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> h[i];
    for (int j = 0; j < i; j++) {
      if (h[j] < h[i]) r[j]++;
      else if (h[j] > h[i]) l[i]++;
    }
  }
  
  int c = 0;
  for (int i = 0; i < n; i++) {
    cout << l[i] << "\t" << r[i] << "\n";
    if (r[i] > 2 * l[i]) c++;
    if (l[i] > 2 * r[i]) c++;
  }
  cout << c << "\n";
  fout << c << "\n";
}
