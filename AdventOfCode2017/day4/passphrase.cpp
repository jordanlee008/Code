#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int hashword(vector<char> w) {
  int sum = 0;
  for (int i = 0; i < w.size(); i++) {
    sum += (w[i] - 'a') * (w[i] - 'a') * (26 - (w[i] - 'a'));
  }
  return sum;
}

int main() {
  ifstream fin ("passphrase.in");
  ofstream fout ("passphrase.out");
  
  string line;
  int valid = 0;
  while (getline(fin, line)) {
    // get input
    line += " ";
    vector< vector<char> > l;
    vector<char> w;
    vector<int> h;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ' ') {
	l.push_back(w);
	h.push_back(hashword(w));
	//	cout << hashword(w) << " ";
	w.clear();
      } else {
	w.push_back(line[i]);
      }
    }
    //    cout << "\n";

    // check valid
    bool v = true;

    // PART 1
    /* for (int i = 0; i < l.size(); i++) {
      for (int j = 0; j < i; j++) {
	if (l[i] == l[j]) v = false;
      }
      } */
    
    // PART 2
    sort(h.begin(), h.end());
    for (int i = 0; i < h.size()-1; i++) if (h[i] == h[i+1]) v = false;
    
    if (v) valid++;

  }
  
  fout << valid << "\n";
}
