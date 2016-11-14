#include "mod.cpp"
#include <iostream>

using namespace std;

int main() {
  Mod::set_modulus(9223372036854775783);
  Mod a(123456789987654321);
  a += a;
  cout << a << endl;
}
