#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  int n = 0;
  for (int a = 0; a < 5; a++) {
    for (int b = 0; b < 5; b++) {
      for (int c = 0; c < 5; c++) {
	for (int d = 0; d < 5; d++) {
	  for (int e = 0; e < 5; e++) {
	    vector<int> v;
	    v.push_back(a);
	    v.push_back(b);
	    v.push_back(c);
	    v.push_back(d);
	    v.push_back(e);
	    bool b = true;
	    for (int i = 0; i < 5; i++) {
	      if (v[v[v[i]]] != v[v[i]]) b = false;
	    }
	    if (b) n++;
	  }
	}
      }
    }
  }

  cout << n << "\n";
  
  return 0;
}
