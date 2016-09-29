#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int wildcard (string a) {
  int as = a.size();
  for (int i = 0; i < as; i++) {
    if (a[i] == '.') {
      return i;
    }
  }
  return -1;
}

vector<int> bracketwildcard (string a) {
  vector<int> b (2, -1);
  int as = a.size();
  int i = 0;
  while ((b[0] == -1) && (i < as)) {
    if (a[i] == '[')
      b[0] = i;
    i++;
  }
  while ((b[1] == -1) && (i < as)) {
    if (a[i] == ']')
      b[1] = i;
    i++;
  }
  return b;
}

vector<int> notbracketwildcard (string a) {
  vector<int> b (2, -1);
  int as = a.size();
  int i = 0;
  while ((b[0] == -1) && (i < as - 1)) {
    if ((a[i] == '[') && (a[i + 1] == '^'))
      b[0] = i;
    i++;
  }
  while ((b[1] == -1) && (i < as)) {
    if (a[i] == ']')
      b[1] = i;
    i++;
  }
  return b;
}

int repeat (string a) {
  int as = a.size();
  for (int i = 0; i < as; i++) {
    if (a[i] == '*') {
      return i;
    }
  }
  return -1;
}

int repeatspecial (string a) {
  int as = a.size();
  for (int i = 0; i < as - 5; i++) {
    if (a[i] == '{')
      return i;
  }
  return -1;
}

int main() {
  ifstream fin ("regularexpression.in");
  ofstream fout ("regularexpression.out");
  
  vector<string> s1;

  for (int i = 0; i < 10; i++) {
    string a;
    fin >> a;
    s1.push_back(a);
  }
  
  for (int i = 0; i < 5; i++) {
    string a;
    fin >> a;
    if (wildcard(a) != -1) {
      cout << "wildcard" << endl;
      int x = wildcard(a);
      string b = a;
      b[x] = 'a';
      cout << b << endl;
      for (int j = 0; j < 10; j++) {
	if (b == s1[j])
	  fout << b << " ";
      }
      b[x] = 'b';
      cout << b << endl;
      for (int j = 0; j < 10; j++) {
	if (b == s1[j])
	  fout << b << " ";
      }
      b[x] = 'c';
      cout << b << endl;
      for (int j = 0; j < 10; j++) {
	if (b == s1[j])
	  fout << b << " ";
      }
      b[x] = '#';
      cout << b << endl;
      for (int j = 0; j < 10; j++) {
	if (b == s1[j])
	  fout << b << " ";
      }
    } else if (notbracketwildcard(a)[1] != -1) {
      cout << "notbracketwildcard" << endl;
      vector<int> x = notbracketwildcard(a);
      char y[] = {'a', 'b', 'c'};
      string b = "";
      for (int j = 0; j < x[0]; j++)
	b.push_back(a[j]);
      b.push_back(' ');
      for (int j = x[1] + 1; j < a.size(); j++)
	b.push_back(a[j]);
      for (int j = 0; j < 3; j++) {
	bool found = false;
	b[x[0]] = y[j];
	for (int k = x[0] + 1; k < x[1]; k++) {
	  if (y[j] == a[k])
	    found = true;
	}
	if (!found) {
	  cout << b << endl;
	  for (int l = 0; l < 10; l++) {
	    if (b == s1[l])
	      fout << b << " ";
	  }
	}
      }
    } else if (bracketwildcard(a)[1] != -1) {
      cout << "bracketwildcard" << endl;
      vector<int> x = bracketwildcard(a);
      string b = "";
      for (int j = 0; j < x[0]; j++)
	b.push_back(a[j]);
      b.push_back(' ');
      for (int j = x[1] + 1; j < a.size(); j++)
	b.push_back(a[j]);
      for (int j = x[0] + 1; j < x[1]; j++) {
	b[x[0]] = a[j];
	cout << b << endl;
	for (int k = 0; k < 10; k++) {
	  if (b == s1[k])
	    fout << b << " ";
	}
      }
    } else if (repeat(a) != -1) {
      cout << "repeat" << endl;
      int x = repeat(a);
      string b1, b2;
      for (int j = 0; j < x - 1; j++)
	b1.push_back(a[j]);
      for (int j = x + 1; j < a.size(); j++)
	b2.push_back(a[j]);
      for (int j = 0; j < 6; j++) {
	string b;
	b = b1;
	for (int k = 0; k < j; k++)
	  b.push_back(a[x - 1]);
	for (int k = 0; k < b2.size(); k++)
	  b.push_back(b2[k]);
	cout << b << endl;
	for (int k = 0; k < 10; k++)
	  if (b == s1[k])
	    fout << b << " ";
      }
    } else if (repeatspecial(a) != -1) {
      cout << "repeatspecial" << endl;
      int x = repeatspecial(a);
      cout << a[x + 1] << a[x + 3] << endl;
      int x1 = a[x + 1] - '0';
      int x2 = a[x + 3] - '0';
      string b1, b2;
      for (int j = 0; j < x - 1; j++)
	b1.push_back(a[j]);
      for (int j = x + 5; j < a.size(); j++)
	b2.push_back(a[j]);
      for (int j = x1; j <= x2; j++) {
	string b;
	b = b1;
	for (int k = 0; k < j; k++)
	  b.push_back(a[x - 1]);
	for (int k = 0; k < b2.size(); k++)
	  b.push_back(b2[k]);
	cout << b << endl;
	for (int k = 0; k < 10; k++)
	  if (b == s1[k])
	    fout << b << " ";
      }
    }
    
    
    fout << endl;
  }
  
  
  return 0;
}
