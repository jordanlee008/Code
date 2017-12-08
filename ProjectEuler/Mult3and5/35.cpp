#include <iostream>

using namespace std;

bool check3(int n) {
  if (n % 3 == 0)
    return true;
  return false;
}

bool check5(int n) {
  if (n % 5 == 0)
    return true;
  return false;
}

int main(void) {
  int output = 0;
  for (int i = 0; i < 1000; i++)
    if (check5(i) || check3(i))
      output += i;
  cout << output << endl;
}//end main
