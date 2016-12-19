#include <iostream>
#include <vector>
#include <string>

using namespace std;

int val(string a) {
  char s = a[0];
  switch (s) {
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  case 'T':
    return 10;
  case 'J':
    return 11;
  case 'Q':
    return 12;
  case 'K':
    return 13;
  case 'A':
    return 1;
  }
}

// assuming that they are the same suit (we don't care)
bool cless(string a, string b) {
  return val(a) < val(b);
}

string agram(vector<string> a) {
  // check for cards of same suit
  vector<string> match1; // not greater than the thing necessarily
  vector<string> match2; // greater than the thing necessarily
  for (int i = 1; i < 6; i++) {
    if (a[i][1] == a[0][1]) {
      match1.push_back(a[i]);
      if (cless(a[0], a[i])) match2.push_back(a[i]);
    }
  }
  
  if (match2.size()) {
    int small = 0;
    for (int i = 1; i < match2.size(); i++) {
      if (cless(match2[i], match2[small])) small = i;
    }
    return match2[small];
  }
  
  if (match1.size()) {
    int small = 0;
    for (int i = 1; i < match1.size(); i++) {
      if (cless(match1[i], match1[small])) small = i;
    }
    return match1[small];
  }
  
  // there are no cards of the same suit
  int small = 1;
  for (int i = 2; i < a.size(); i++) {
    if (cless(a[i], a[small])) small = i;
  }
  
  vector<string> o;
  for (int i = 1; i < a.size(); i++) {
    if (a[i][0] == a[small][0]) o.push_back(a[i]);
  }
  
  for (int i = 0; i < o.size(); i++) {
    if (o[i][1] == 'C') return o[i];
  }
  for (int i = 0; i < o.size(); i++) {
    if (o[i][1] == 'D') return o[i];
  }
  for (int i = 0; i < o.size(); i++) {
    if (o[i][1] == 'H') return o[i];
  }
  for (int i = 0; i < o.size(); i++) {
    if (o[i][1] == 'S') return o[i];
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    vector<string> a;
    for (int j = 0; j < 6; j++) {
      string s;
      cin >> s;
      a.push_back(s);
    }
    cout << agram(a) << "\n";
  }
}
