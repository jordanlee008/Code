#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

void spin(int n, vector<int>& p, vector<int>& w) {
  for (int i = 0; i < w.size(); i++) w[i] = (w[i] + n) % w.size();
  vector<int> v(p.end() - n, p.end());
  v.insert(v.end(), p.begin(), p.end() - n);
  p = v;
}

void exch(int a, int b, vector<int>& p, vector<int>& w) {
  swap(w[p[a]], w[p[b]]);
  swap(p[a], p[b]);
}

void part(char a, char b, vector<int>& p, vector<int>& w) {
  swap(p[w[a - 'a']], p[w[b - 'a']]);
  swap(w[a - 'a'], w[b - 'a']);
}

int main() {
  ifstream fin ("dance.in");
  ofstream fout ("dance.out");
  
  vector<int> p; // indexed by position
  vector<int> p0;
  vector<int> w; // indexed by character
  for (int i = 0; i < 16; i++) {
    p0.push_back(i);
    p.push_back(i);
    w.push_back(i);
  }
  
  string s;
  fin >> s;
  char c;
  
  for (int i = 0; i < 1000000000; i++) {
    if (p == p0) {
      int step = i;
      while (i < 1000000000) i += step;
    }
    //    if (i % 10 == 0) cout << i / 10 << "\n";
    int j = 0;
    while (j < s.length()) {
      c = s[j];
      j++;
      if (c == 's') {
	string ns;
	while (s[j] != ',' && j < s.length()) {
	  c = s[j];
	  j++;
	  ns += c;
	}
	j++;
	//      cout << "s " << atoi(ns.c_str()) << "\n";
	spin(atoi(ns.c_str()), p, w);
      } else if (c == 'x') {
	string ns1, ns2;
	while (s[j] != '/' && j < s.length()) {
	  c = s[j];
	  j++;
	  ns1 += c;
	}
	j++;
	while (s[j] != ',' && j < s.length()) {
	  c = s[j];
	  j++;
	  ns2 += c;
	}
	j++;
	//      cout << "x " << atoi(ns1.c_str()) << " " << atoi(ns2.c_str()) << "\n";
	exch(atoi(ns1.c_str()), atoi(ns2.c_str()), p, w);
      } else if (c == 'p') {
	char c1, c2;
	c1 = s[j];
	j++;
	c = s[j];
	j++;
	c2 = s[j];
	j++;
	j++;
	//      cout << "p " << c1 << " " << c2 << "\n";
	part(c1, c2, p, w);
      } else {
	cout << c << " ";
      }
      /*    for (int i = 0; i < p.size(); i++) {
	    cout << char(p[i] + 'a');
	    } cout << "\n";*/
    }
  }

  
  for (int i = 0; i < p.size(); i++) {
    fout << char(p[i] + 'a');
  } fout << "\n";
  for (int i = 0; i < w.size(); i++) {
    fout << w[i] << " ";
  } fout << "\n";
}
