#include "mod.cpp"
#include <iostream>

using namespace std;

int main() {
  Mod::set_modulus(17);
  Mod m = 12;
  cout << -m << endl; // 5
  cout << m.pwr(3) << endl; // 11
  m -= 6;
  cout << "1 " << m << endl; // 6
  m /= 2;
  cout << "2 " << m << endl; // 3
  m *= 17;
  cout << "3 " << m << endl; // 0
  m += 13;
  cout << "4 " << m << endl; // 13
}
