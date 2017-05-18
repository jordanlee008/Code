#include <iostream>
#include <vector>

using namespace std;

#define vector<int> VI
#define vector<VI> VVI
#define vector<VVI> VVVI

int N;
vector<string> spc; // string of pieces
VVVI pc;
VI dim;

VVI conv_piece(string s) {
  
}



int main() {
  // get input
  cin >> N;
  for (int i = 0; i < N; i++) {
    spc.push_back("");
    cin >> spc[i];
  }
  for (int i = 0; i < 3; i++) { dim.push_back(0); cin >> dim[i]; }
  
  
  return 0;
}
