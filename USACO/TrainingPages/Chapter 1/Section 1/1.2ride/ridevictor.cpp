/*
ID: jorlee
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string comet, group;
  int cometInt = 1, groupInt = 1;
  fin >> comet >> group;
  for (int i = 0; i < comet.length(); i++)
    cometInt *= (comet[i] - 'A' + 1);
  for (int i = 0; i < group.length(); i++)
    groupInt *= (group[i] - 'A' + 1);
  if (cometInt % 47 == groupInt % 47)
    fout << "GO\n";
  else
    fout << "STAY\n";
}//end main
