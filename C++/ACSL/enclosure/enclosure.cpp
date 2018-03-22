/*
  Jordan Lee
  Bergen County Academies
  Senior Division
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

int main() {
  ifstream fin ("big.txt");
  for (int i = 0; i < 5; i++) {
    string s;
    fin >> s;
    cout << s << "\n";
    
    vector<int> o;
    vector< vector<int> > o1 = {{0},{},{},{}};// places for an opening brace
    vector< vector<int> > o2 = {{},{},{},{}};// places for a closing brace
    int p = 1; // previously saw: 0=int, 1=oper, 2=enclosure
    vector<int> s1 = {0,0,0}; // s[0] = (, s[1] = [, s[2] = {
    deque<int> s2 = {}; // looking for 0 = ), 1 = ], 2 = }
    bool past_int = false;
    
    for (int j = 0; j < s.length(); j++) {
      char c = s[j];
      if (p == 0) {
	if (c > 41 && c < 48) {
	  p = 1; // 0 + h
	  o1[s2.size()].push_back(j+1);
	  if (!past_int) o2[s2.size()].push_back(j);
	  past_int = false;
	} else if (c > 47 && c < 58) {
	  continue;
	}
	else if ((s2.size() == 0) || (c == ')' && !s1[0]) || (c == ']' && !s1[1]) || (c == '}' && !s1[2])) {
	  o = vector<int>(o1[s2.size()].begin(),o1[s2.size()].end()-1);
	  p = 2;
	  /*cout << "found1 at " << j << "\n";
	  for (int l = 0; l < s1.size(); l++) cout << s1[l];
	  cout << "\n";*/
	}
	else if ((s2.size() > 1) && ((c == ')' && s2[1] == 0) || (c == ']' && s2[1] == 1) || (c == '}' && s2[1] == 2))) {
	  o2[s2.size()].push_back(j);
	  o = vector<int>(o2[s2.size()].begin(),o2[s2.size()].end());
	  p = 2;
	  /*cout << "found2 at " << j << "\n";
	  for (int l = 0; l < s1.size(); l++) cout << s1[l];
	  cout << "\n";*/
	}
	else {
	  past_int = false;
	  p = 2;
	  s2.pop_front();
	  o2[s2.size()].push_back(j+1);
	}
      } else if (p == 1) {
	if (c > 47 && c < 58) { // on an int
	  p = 0; // + 0 h
	} // on an enclosure
	else if (c == '(') {
	  s1[0] = 1;
	  s2.push_front(0);
	  o1[s2.size()].push_back(j+1);
	  past_int = true;
	}
	else if (c == '[') {
	  s1[1] = 1;
	  s2.push_front(1);
	  o1[s2.size()].push_back(j+1);
	  past_int = true;
	}
	else if (c == '{') {
	  s1[2] = 1;
	  s2.push_front(2);
	  o1[s2.size()].push_back(j+1);
	  past_int = true;
	}
	else { cout << "what.\n"; } // two operator in a row?
      } else { // we saw an operator before
	if (c > 41 && c < 48) { // we are on operator
	  p = 1; // ) +
	  o1[s2.size()].push_back(j+1);
	} else if (c > 47 && c < 58) { // we are on int
	  p = 0; // ( 3
	} // we are on enclosure
	else if (c == '(') {
	  s1[0] = 1;
	  s2.push_front(0);
	  o1[s2.size()].push_back(j+1);
	  past_int = true;
	}
	else if (c == '[') {
	  s1[1] = 1;
	  s2.push_front(1);
	  o1[s2.size()].push_back(j+1);
	  past_int = true;
	}
	else if (c == '{') {
	  s1[2] = 1;
	  s2.push_front(2);
	  o1[s2.size()].push_back(j+1);
	  past_int = true;
	}
	else if ((s2.size() > 1) && ((c == ')' && s2[1] == 0) || (c == ']' && s2[1] == 1) || (c == '}' && s2[1] == 2))) {
	  o2[s2.size()].push_back(j);
	  o = o2[s2.size()];
	  p = 2;
	  /*cout << "found2 at " << j << "\n";
	  for (int l = 0; l < s1.size(); l++) cout << s1[l];
	  cout << "\n";*/
	}
	else if ((s2.size() == 0) || (c == ')' && !s1[0]) || (c == ']' && !s1[1]) || (c == '}' && !s1[2])) {
	  o = o1[s2.size()];
	  p = 2;
	  /*cout << "found1 at " << j << "\n";
	  for (int l = 0; l < s1.size(); l++) cout << s1[l];
	  cout << "\n";*/
	}
	else {
	  p = 2;
	  s2.pop_front();
	  o2[s2.size()].push_back(j+1);
	}
      }
    }
    
    if (o.size() == 0) {
      o2[s2.size()].push_back(s.size());
      o = vector<int>(o2[s2.size()].begin(),o2[s2.size()].end());
    }
    for (int j = 0; j < o.size(); j++) {
      if (j == 0 || o[j] != o[j-1]) {
	cout << o[j]+1 << " ";
      }
    }
    cout << "\n";
  }
    
}
