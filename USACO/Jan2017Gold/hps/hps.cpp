#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, k;
int fj[100000];
vector< vector<int> > j;
int h[100000][3];

int solve() {
  if (k == 0) return max(h[n - 1][0], max(h[n - 1][1], h[n - 1][2]));
  int s = 0;
  vector< vector<int> > hands;
  vector<int> empty;
  empty.push_back(0);
  if (h[n - 1][0] >= h[n - 1][1] && h[n - 1][0] >= h[n - 1][2]) {
    empty.push_back(0);
    hands.push_back(empty);
  } else if  (h[n - 1][1] >= h[n - 1][0] && h[n - 1][1] >= h[n - 1][2]) {
    empty.push_back(1);
    hands.push_back(empty);
  } else {
    empty.push_back(2);
    hands.push_back(empty);
  }
  empty[0] = j.size() - 1;
  hands.push_back(empty);

  while (s < k) {
    int where = -1;
    int what = -1;
    int good = 0;
    int hand = 0;
    for (int i = 1; i < j.size() - 1; i++) {
      while (i > hands[hand][0]) hand++;
      int t = (hands[hand - 1][1] + 1) % 3;
      int score = h[j[hands[hand][0]][2] - 1][t] - h[j[i][2]][t] - (h[j[hands[hand][0]][2] - 1][hands[hand - 1][1]] - h[j[i][2]][hands[hand - 1][1]]);
      if (score > good) {
	where = i;
	what = t;
	good = score;
      }
      t = (hands[hand - 1][1] + 2) % 3;
      score = h[j[hands[hand][0]][2] - 1][t] - h[j[i][2]][t] - (h[j[hands[hand][0]][2] - 1][hands[hand - 1][1]] - h[j[i][2]][hands[hand - 1][1]]);
      if (score > good) {
	where = i;
	what = t;
	good = score;
      }
    }

    empty[0] = where;
    empty[1] = what;
    for (int m = 0; m < hands.size(); m++) {
      if (where < hands[m][0]) {
	hands.insert(hands.begin() + m - 1, empty);
      }
    }
    
    s++;
  }
  int score = 0;
  score += h[j[hands[0][0]][2]][hands[0][1]];
  for (int i = 0; i < hands.size() - 1; i++) {
    score += h[j[hands[i + 1][0]][2] - 1][hands[i][1]] - h[j[hands[i][0]][2]][hands[i][1]];
  }
  return score;
}

int main() {
  ifstream fin ("hps.in");
  ofstream fout ("hps.out");
  
  fin >> n >> k;
  string c;
  fin >> c;
  if (c == "H") {
    fj[0] = 0;
    h[0][0]++;
    vector<int> blah;
    blah.push_back(0);
    blah.push_back(1);
    blah.push_back(0);
    j.push_back(blah);
  } else if (c == "P") {
    fj[0] = 1;
    h[0][1]++;
    vector<int> blah;
    blah.push_back(1);
    blah.push_back(1);
    blah.push_back(0);
    j.push_back(blah);
  } else if (c == "S") {
    fj[0] = 2;
    h[0][2]++;
    vector<int> blah;
    blah.push_back(2);
    blah.push_back(1);
    blah.push_back(0);
    j.push_back(blah);
  }
  
  for (int i = 1; i < n; i++) {
    h[i][0] = h[i - 1][0];
    h[i][1] = h[i - 1][1];
    h[i][2] = h[i - 1][2];
    fin >> c;
    if (c == "H") {
      fj[i] = 0;
      h[i][0]++;
      if (j[j.size() - 1][0] == 0) {
	j[j.size() - 1][1]++;
	j[j.size() - 1][2]++;
      }
      else {
	vector<int> blah;
	blah.push_back(0);
	blah.push_back(1);
	blah.push_back(j[j.size() - 1][2] + 1);
	j.push_back(blah);
      }
    } else if (c == "P") {
      fj[i] = 1;
      h[i][1]++;
      if (j[j.size() - 1][0] == 1) {
	j[j.size() - 1][1]++;
	j[j.size() - 1][2]++;
      }
      else {
	vector<int> blah;
	blah.push_back(1);
	blah.push_back(1);
	blah.push_back(j[j.size() - 1][2] + 1);
	j.push_back(blah);
      }
    } else if (c == "S") {
      fj[i] = 2;
      h[i][2]++;
      if (j[j.size() - 1][0] == 2) {
	j[j.size() - 1][1]++;
	j[j.size() - 1][2]++;
      }
      else {
	vector<int> blah;
	blah.push_back(2);
	blah.push_back(1);
	blah.push_back(j[j.size() - 1][2] + 1);
	j.push_back(blah);
      }
    }
  }
  vector<int> blah;
  blah.push_back(-1);
  blah.push_back(-1);
  blah.push_back(n);
  j.push_back(blah);

  for (int i = 0; i < j.size(); i++) {
    for (int m = 0; m < j[i].size(); m++) cout << j[i][m];
    cout << "\n";
  }

  cout << solve() << "\n";
  //  fout << solve() << "\n";

}
