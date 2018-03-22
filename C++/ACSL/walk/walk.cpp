/* Jordan Lee
   Bergen County Academies
   5-Person Senior
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> ip;

vector<int> make_row(string s) {
  long int n = 0;
  for (int i = 0; i < s.length(); i++) {
    n *= 16;
    if (s[i] <= 57 && s[i] >= 48) {
      n += s[i] - 48;
      //cout << s[i] - 48 << " ";
    } else {
      n += s[i] - 65 + 10;
      //cout << s[i] - 65 + 10 << " ";
    }
  }
  //cout << n << " ";
  
  vector<int> v;
  while (n) {
    v.push_back(n % 8);
    n /= 8;
  }
  
  /*  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
    } cout << "\n"; */
  
  return v;
}

int main() {
  ifstream fin ("c_3_sr_sample.txt");

  vector<string> vs;
  for (int i = 0; i < 8; i++) {
    string s;
    fin >> s;
    vs.push_back(s);
  }
  
  vector<ip> start;
  vector<ip> turn;
  for (int i = 0; i < 5; i ++) {
    int x0,y0;
    char c0;
    int d0,t0;
    fin >> x0 >> y0 >> c0 >> t0;
    start.push_back(make_pair(x0,y0));
    if (c0 == 'A') turn.push_back(make_pair(4,t0));
    else if (c0 == 'R') turn.push_back(make_pair(6,t0));
    else if (c0 == 'B') turn.push_back(make_pair(0,t0));
    else if (c0 == 'L') turn.push_back(make_pair(2,t0));
    else cerr << "wrong c0\n";
  }

  vector< vector<int> > board (8, vector<int>(8,0));
  for (int i = 0; i < vs.size(); i++) {
    vector<int> v0 = make_row(vs[i]);
    for (int j = 0; j < 8; j++) {
      board[i][j] = v0[7 - j];
    }
  }

  /*  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    } cout << "\n";
    } // board[x][y] */
  
  for (int i = 0; i < 5; i++) {
    int x = start[i].first-1, y = start[i].second-1;
    int d = turn[i].first, t = turn[i].second;
    
    for (int j = 0; j < t; j++) {
      //cout << x << " " << y << " " << d << "\n";
      d = (d + 4) % 8; d = (d + board[x][y]) % 8;
      if (d == 0) { x = (x + 1) % 8; }
      else if (d == 1) { x = (x + 1) % 8; y = (y + 1) % 8; }
      else if (d == 2) { y = (y + 1) % 8; }
      else if (d == 3) { x = (x + 7) % 8; y = (y + 1) % 8; }
      else if (d == 4) { x = (x + 7) % 8; }
      else if (d == 5) { x = (x + 7) % 8; y = (y + 7) % 8; }
      else if (d == 6) { y = (y + 7) % 8; }
      else if (d == 7) { x = (x + 1) % 8; y = (y + 7) % 8; }
    }
    cout << x+1 << " " << y+1 << "\n";
  }
  
  return 0;
}
