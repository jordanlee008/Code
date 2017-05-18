#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector< vector< vector<int> > > r (2, vector< vector<int> >());

void gen(int len, vector<int> r0) {
  if (r0.size() == len) {
    if (len == 4) r[0].push_back(r0);
    else r[1].push_back(r0);
  }
  vector<int> seen(len + 1, 0);
  for (int i = 0; i < r0.size(); i++) seen[r0[i]] = 1;
  for (int i = 1; i <= len; i++) {
    if (!seen[i]) {
      vector<int> r1 = r0;
      r1.push_back(i);
      gen(len, r1);
    }
  }
}

bool check(int l, vector<int> t) {
  vector<int> seen(N + 1,0);
  for (int i = 0; i < N; i++) {
    //    cout << t[i] << " ";
    seen[t[i]] = 1;
  }
  //  cout << l << "\n";
  for (int i = 1; i < N + 1; i++) if (!seen[i]) return false;
  
  int c = 1;
  int h = t[0];
  for (int i = 1; i < N; i++) {
    //    cout << h << " "<< t[i] << " " << c << "\n";
    if (t[i] > h) {
      c++;
      h = t[i];
    }
  }
  return c == l;
}

void print(vector< vector<int> > b) {
  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < b[i].size(); j++) {
      cout << b[i][j];
    }
    cout << " ";
  }
  cout << "\n";
}

void find(vector<int> l, vector< vector<int> > b) {
  int c = b.size(); // rows already existing
  //  cout << c << "\n";
  /*  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < N; j++) {
      cout << b[i][j];
    }
    cout << "\n";
  }
  cout << "\n";*/

  if (c == N) {
    bool out = true;
    for (int i = 0; i < N; i++) {
      vector<int> v;
      for (int j = 0; j < N; j++) {
	v.push_back(b[j][i]);
      }
      if (!check(l[i], v)) out = false;
    }
    
    for (int i = 0; i < N; i++) {
      vector<int> v;
      for (int j = N - 1; j >= 0; j--) {
	v.push_back(b[j][i]);
      }
      if (!check(l[3*N + i], v)) out = false;
    }
    if (out) {
      //      cout << "found ";
      print(b);
    }
    return;
  }
  
  
  for (int i = 0; i < r[N-4].size(); i++) {
    vector<int> rev;
    for (int j = 0; j < N; j++) rev.push_back(r[N-4][i][N-j-1]);
    if (check(l[N + 2*c], r[N-4][i]) && check(l[N + 2*c + 1], rev)) {
      vector< vector<int> > b1 = b;
      b1.push_back(r[N-4][i]);
      find(l, b1);
    }
  }
}

int main() {
  ifstream fin ("skyscraper.in");
  ofstream fout ("skyscraper.out");
  
  gen(4, vector<int>());
  //  cout << r[0].size() << "\n";
  gen(5, vector<int>());
  //  cout << r[1].size() << "\n";
  
  /*  for (int i = 0; i < 120; i++) {
    for (int j = 0; j < 5; j++) cout << r[1][i][j];
    cout << "\n";
    }*/

  N = 4;
  for (int i = 0; i < 3; i++) {
    vector<int> l (N*4,0);
    for (int j = 0; j < N*4; j++) {
      fin >> l[j];
      //      cout << l[j];
    }
    //    cout << "4:" << i << "\n";
    find(l, vector< vector<int> >());
  }
  N = 5;
  for (int i = 0; i < 2; i++) {
    vector<int> l(N*4,0);
    for (int j = 0; j < N*4; j++) {
      fin >> l[j];
    }
    //    cout << "5:" << i << "\n";
    find(l, vector< vector<int> >());
  }

}
