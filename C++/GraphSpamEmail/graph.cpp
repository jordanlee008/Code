#include <iostream>

using namespace std;

long long int counter;

void pass (string name, int round) {
  int nround = round + 1;
  if (round == 30 && name == "Mad") {
    counter++;
    return;
  } else if (round == 30) {
    return;
  }
  if (name == "Mad") {
    cout << "Mad has received" << endl;
    pass ("Kelsey", nround);
    pass ("s-m", nround);
  }
  else if (name == "Kelsey") {
    cout << "Kelsey has received" << endl;
    pass ("Mad", nround);
    pass ("s-m", nround);
    pass ("Tom", nround);
  }
  else if (name == "s-m") {
    cout << "s-m has received" << endl;
    pass ("Mad", nround);
    pass ("Kelsey", nround);
    pass ("Nate", nround);
    pass ("Hannah", nround);
    pass ("Tom", nround);
    pass ("Lisa", nround);
  }
  else if (name == "Lisa") {
    cout << "Lisa has received" << endl;
    pass ("s-m", nround);
    pass ("Tom", nround);
  }
  else if (name == "Tom") {
    cout << "Tom has received" << endl;
    pass ("Brian", nround);
    pass ("Hannah", nround);
    pass ("Kelsey", nround);
    pass ("s-m", nround);
    pass ("Lisa", nround);
  }
  else if (name == "Brian") {
    cout << "Brian has received" << endl;
    pass ("Tom", nround);
  }
  else if (name == "Hannah") {
    cout << "Hannah has received" << endl;
    pass ("Tom", nround);
    pass ("s-m", nround);
    pass ("Nate", nround);
  }
  else if (name == "Nate") {
    cout << "Nate has received" << endl;
    pass ("s-m", nround);
    pass ("Hannah", nround);
  }
  return;
}

int main () {
  counter = 0;
  pass ("Mad", 0);
  cout << counter << endl;
  return 0;
}
