#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main() {
  deque<int> v;
  int x;
  cin >> x;
  while (x != 0) {
    v.push_back(x);
    cin >> x;
  }
  
  for (int i = 0; i < 10; i++) {
    deque<int> v0 = v;
    
    char c;
    cin >> c;
    
    string s;
    cin >> s;
    
    if (c == 'S') {
      while (s != "E") {
	if (s == "P") {
	  v0.pop_back();
	} else if (s[0] == 'P') {
	  v0.push_back(s[2] - '0');
	} else if (s == "L") {
	  int siz = 10, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] < siz) { siz = v[j]; ind = j; }
	  }
	  v0.erase(v0.begin() + ind);
	} else if (s[0] == 'L') {
	  int siz = 10, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] < siz) { siz = v[j]; ind = j; }
	  }
	  v0.insert(v0.begin() + ind, s[2] - '0');
	} else if (s == "H") {
	  int siz = 0, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] >= siz) { siz = v[j]; ind = j; }
	  }
	  v0.erase(v0.begin() + ind);
	} else if (s[0] == 'H') {
	  int siz = 0, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] >= siz) { siz = v[j]; ind = j; }
	  }
	  v0.insert(v0.begin() + ind + 1, s[2] - '0');
	} else if (s[0] == 'M') {
	  deque<int> d0 = v0;
	  sort(d0.begin(), d0.end());
	  int med = d0[(d0.size()+1) / 2 - 1];
	  int ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] == med) { ind = j; break; }
	  }
	  v0.insert(v0.begin() + ind, s[2] - '0');
	} else {
	  cout << "help\n";
	}
	cin >> s;
      }
    } else if (c == 'Q') {
      while (s != "E") {
	if (s == "P") {
	  v0.pop_front();
	} else if (s[0] == 'P') {
	  v0.push_back(s[2] - '0');
	} else if (s == "L") {
	  int siz = 10, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] < siz) { siz = v[j]; ind = j; }
	  }
	  v0.erase(v0.begin() + ind);
	} else if (s[0] == 'L') {
	  int siz = 10, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] < siz) { siz = v[j]; ind = j; }
	  }
	  v0.insert(v0.begin() + ind, s[2] - '0');
	} else if (s == "H") {
	  int siz = 0, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] >= siz) { siz = v[j]; ind = j; }
	  }
	  v0.erase(v0.begin() + ind);
	} else if (s[0] == 'H') {
	  int siz = 0, ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] >= siz) { siz = v[j]; ind = j; }
	  }
	  v0.insert(v0.begin() + ind + 1, s[2] - '0');
	} else if (s[0] == 'M') {
	  deque<int> d0 = v0;
	  sort(d0.begin(), d0.end());
	  int med = d0[(d0.size()+1) / 2 - 1];
	  
	  int ind = -1;
	  for (int j = 0; j < v.size(); j++) {
	    if (v[j] == med) { ind = j; break; }
	  }
	  v0.insert(v0.begin() + ind, s[2] - '0');
	} else {
	  cout << "help\n";
	}
	cin >> s;
      }
    }

    
    for (int j = 0; j < v0.size(); j++) cout << v0[j] << " ";
    cout << "\n";
  }
}
