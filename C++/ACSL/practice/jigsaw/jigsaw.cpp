#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ip;

int main() {
  int in;
  vector<int> i0;
  cin >> in;
  while (in != 0) {
    i0.push_back(in);
    cin >> in;
  }


  vector< vector<int> > b (10, vector<int>(10,1));
  for (int i = 0; i < i0.size(); i++) {
    b[(i0[i] - 1) % 10][(i0[i] - 1) / 10] = 0;
  }
  
  vector<ip> A0 = {ip(0,0) , ip(1,0)};
  vector<ip> A1 = {ip(0,0) , ip(0,1)};
  vector<ip> B0 = {ip(0,0) , ip(0,1) , ip(1,1)};
  vector<ip> B1 = {ip(0,0) , ip(0,1) , ip(-1,1)};
  vector<ip> B2 = {ip(0,0) , ip(1,0), ip(1,1)};
  vector<ip> C0 = {ip(0,0) , ip(0,1) , ip(-1,1)};
  vector<ip> C1 = {ip(0,0) , ip(1,0) , ip(1,1)};
  vector<ip> C2 = {ip(0,0) , ip(1,0) , ip(0,1)};
  vector<ip> D0 = {ip(0,0) , ip(1,0) , ip(0,1)};
  vector<ip> D1 = {ip(0,0) , ip(1,1) , ip(0,1)};
  vector<ip> D2 = {ip(0,0) , ip(1,0) , ip(1,1)};


  for (int i = 0; i < 10; i++) {
    char c;
    int a;
    cin >> c >> a;

    vector<ip> dir;
    if (c == 'A') {
      if (a == 0 || a == 180) {
	dir = A0;
      } else if (a == 90) {
	dir = A1;
      } else {
	cout << "darn\n";
      }
    } else if (c == 'B') {
      if (a == 0) {
	dir = B0;
      } else if (a == 90) {
	dir = B1;
      } else if (a == 180) {
	dir = B2;
      } else {
	cout << "darn\n";
      }
    } else if (c == 'C') {
      if (a == 0) {
	dir = C0;
      } else if (a == 90) {
	dir = C1;
      } else if (a == 180) {
	dir = C2;
      } else {
	cout << "darn\n";
      }
    } else if (c == 'D') {
      if (a == 0) {
	dir = D0;
      } else if (a == 90) {
	dir = D1;
      } else if (a == 180) {
	dir = D2;
      } else {
	cout << "darn\n";
      }
    } else {
      cout << "dude\n";
    }

    bool work = true;
    for (int pos = 0; pos < 100; pos++) {
      work = true;
      int x = pos % 10, y = pos / 10;

      for (int j = 0; j < dir.size(); j++) {
	//printf("%d %d\n",x+dir[j].first,y+dir[j].second);
	if (x+dir[j].first > 9 || x+dir[j].first < 0) {
	  work = false;
	  break;
	} else if (y+dir[j].second > 9 || y+dir[j].second < 0) {
	  work = false;
	  break;
	} else {
	  if (!b[x+dir[j].first][y+dir[j].second]) {
	    work = false;
	    break;
	  }
	}
      }

      if (work) {
	for (int j = 0; j < dir.size(); j++) {
	  b[x+dir[j].first][y+dir[j].second] = 0;
	}
	
	cout << pos+1 << "\n";
	break;
      }
    }
    
    if (!work) {
      cout << "NONE\n";
    }

    for (int j = 0; j < 100; j++) {
      if (j % 10 == 0) cout << "\n";
      cout << b[j % 10][j / 10] << " ";
    }
  }
  
}
