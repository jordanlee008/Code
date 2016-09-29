#include <iostream>
#include <vector>
#include <string>

using namespace std;

string char_split(string a, int n, char c) {
  int i = 0;
  string s = "";
  while (i < a.length()) {
    if (((i % n) == 0) && (i != 0)) {
      s += "*";
    }
      s += a[i];
    i++;
  }
  return s;
}

string strrem(string a, string b) {
  int bl = b.length();
  string s = "";
  for (int i = 0; i < a.length() - bl - 1; i++) {
    bool cut = true;
    for (int j = 0; j < bl; j++) {
      if (b[j] != a[i + j])
	cut = false;
    }
    if (cut) {
      for (int j = 0; j < bl; j++)
	s += "";
      i += bl - 1;
    } else {
      s += a[i];
    }
  }
  for (int i = a.length() - bl - 1; i < a.length(); i++) {
    s += a[i];
  }
  return s;
}

string strchrrem(string a, char b) {
  string s = "";
  int i = 0;
  while ((a[i] != b) && (i < a.length())) {
    s += a[i];
    i++;
  }
  return s;
}

string strtok(string a, char b) {
  string s = "";
  string temp = "";
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == b) {
      s += temp;
      s += " ";
      temp = "";
    }
    temp += a[i];
  }
  s += temp;
  return s;
}

string wordwrap(string a, int n, char b) {
  string s = "";
  string temp = "";
  for (int i = 0; i < a.length(); i++) {
    if ((a[i] == b) || (temp.length() == n)) {
      s += temp;
      s += " ";
      temp = "";
    }
    temp += a[i];
  }
  s += temp;
  return s;
}

int main () {
  string s1, s2, s2_2, s3, s4, s5;
  int n1, n5;
  char c1, c3, c4, c5;
  cin >> s1 >> n1 >> c1;
  cin >> s2 >> s2_2;
  cin >> s3 >> c3;
  cin >> s4 >> c4;
  cin >> s5 >> n5 >> c5;
  cout << "1. " << char_split(s1, n1, c1) << endl;
  cout << "2. " << strrem(s2, s2_2) << endl;
  cout << "3. " << strchrrem(s3, c3) << endl;
  cout << "4. " << strtok(s4, c4) << endl;
  cout << "5. " << wordwrap(s5, n5, c5) << endl;
  return 0;
}
