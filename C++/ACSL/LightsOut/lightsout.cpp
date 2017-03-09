#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dx[] = {-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2};
int dy[] = {0, 1, 0, -1, 2, 1, 0, -1, -2, 1, 0, -1, 0};

vector<int> row(const char c) {
  int v;
  vector<int> r;
  if (c <= '9' && c >= '0') {
    v = c - '0';
  } else {
    v = c - 'A' + 10;
  }
  
  for (int i = 0; i < 4; i++) {
    r.push_back(v % 2);
    v /= 2;
  }
  return r;
}

vector< vector<int> > getboard(const string b) {
  vector< vector<int> > bd;
  vector<int> e;
  for (int i = 0; i < 8; i++) e.push_back(0);
  for (int i = 0; i < 8; i++) bd.push_back(e);
  for (int i = 0; i < 16; i++) {
    e = row(b[i]);
    int x = (i % 2) * 4;
    int y = i / 2;
    for (int j = 0; j < 4; j++) bd[x + 3 - j][y] = e[j];
  }
  return bd;
}

vector< vector<int> > presstile(const vector< vector<int> > bd, const int r, const int c) {
  vector< vector<int> > bdcopy = bd;
  for (int i = 0; i < 13; i++) {
    int x = r + dx[i], y = c + dy[i];
    if (x < 0 || x > 7 || y < 0 || y > 7) continue;
    bdcopy[x][y] = !bdcopy[x][y];
  }
  return bdcopy;
}

bool compbd(const vector< vector<int> > bd1, const vector< vector<int> > bd2) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (bd1[i][j] != bd2[i][j]) return false;
    }
  }
  return true;
}

int main() {
  vector<string> in;
  vector< vector< vector<int> > > bds;
  for (int i = 0; i < 6; i++) in.push_back("");
  string s;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> s;
      in[i] += s;
      //      cout << s << "\n";
    }
    bds.push_back(getboard(in[i]));
  }
  //  for (int i = 0; i < 6; i++) cout << in[i] << "\n";

  /*for (int i = 0; i < 6; i++) {
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
	cout << bds[i][x][y] << " ";
      }
      cout << "\n";
    }
    cout << "new board\n";
    }*/
  
  
  /*  vector< vector<int> > blah = presstile(bds[0], 2, 3);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cout << blah[i][j] << " ";
    }
    cout << "\n";
  }*/
  

  vector<string> ans;

  for (int i = 0; i < 5; i++) {
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
	//	printf("%d %d %d\n", i, x, y);
	vector< vector<int> > bd = presstile(bds[i], y, x);
	if (compbd(bd, bds[i + 1])) {
	  ans.push_back("");
	  ans[i] += (x + '1');
	  ans[i] += "";
	  ans[i] += (y + '1');
	}
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
  
}
