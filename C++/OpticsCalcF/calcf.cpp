#include <iostream>

using namespace std;

int main () {
  double d0, di, f;
  cout << "d0?" << endl;
  cin >> d0;
  cout << "f?" << endl;
  cin >> f;
  di = d0*f / (d0 - f);
  cout << di << endl;
}
