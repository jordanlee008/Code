#include <iostream>
#include <vector>
#include <mach/mach_time.h>

using namespace std;

double time() {
    return 1E-9*mach_absolute_time();
}

vector<int> hand(int c) { // return the cards of the hand
  vector<int> h;
  for (int i = 0; i < 5; i++) {
    h.push_back(c % 52);
    c /= 52;
  }
  return h;
}

// returns the value of the card, to compare
// c[0] contains the type of hand
// c[1-5] contains the cards sorted in order of importance and then by value
vector<int> val(int c) {
  vector<int> cs = hand(c); // unpack cards into vector
  int values[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // holds how many of each card there are in the hand (0 - 12)
  for (int i = 0; i < 5; i++) values[cs[i] / 4]++;
  bool flush = true; // holds whether the hand is a flush
  for (int i = 1; i < 5; i++) if (cs[i] % 4 != cs[i - 1] % 4) flush = false;

  vector<int> cv; // holds final value vector that we will return
  // check for straight/flush
  int index = 0;
  while (values[index] == 0) index++;
  bool straight = true;
  for (int i = 0; i < 5; i++)
    if (values[index++] != 1)
      straight = false;
  if (values[0] == 1 && values[1] == 1 && values[2] == 1 && values[3] == 1 && values[12] == 1) straight = true;
  if (straight && flush) {
    cv.push_back(8);
    for (int i = 1; i <= 5; i++) cv.push_back(index - i);
    return cv;
  } else if (flush) { // flush cannot be four / full
    cv.push_back(5);
    for (int i = 12; i >= 0; i--) {
      for (int j = 0; j < values[i]; j++) cv.push_back(i);
    }
    return cv;
  } else if (straight) {
    cv.push_back(4);
    for (int i = 12; i >= 0; i--) if (values[i]) cv.push_back(i);
    return cv;
  }

  // check for four of a kind
  for (int i = 0; i < 13; i++)
    if (values[i] == 4) {
      cv.push_back(7);
      for (int j = 0; j < 4; j++) cv.push_back(i);
      for (int j = 0; j < 13; j++) if (values[j] == 1) cv.push_back(j);
      return cv;
    }

  // check for fullhouse / triple / doubledouble / double
  int triple = -1, double1 = -1, double2 = -1;
  for (int i = 12; i >= 0; i--) {
    if (values[i] == 3) triple = i;
    if (values[i] == 2 && double1 == -1) double1 = i;
    else if (values[i] == 2) double2 = i;
  }
  if (triple > -1 && double1 > -1) {
    cv.push_back(6);
    for (int i = 0; i < 3; i++) cv.push_back(triple);
    for (int i = 0; i < 2; i++) cv.push_back(double1);
    return cv;
  } else if (triple > -1) {
    cv.push_back(3);
    for (int i = 0; i < 3; i++) cv.push_back(triple);
    for (int i = 12; i >= 0; i--)
      for (int j = 0; j < values[i]; j++)
	cv.push_back(i);
    return cv;
  } else if (double1 > -1 && double2 > -1) {
    cv.push_back(2);
    for (int i = 0; i < 2; i++) cv.push_back(double1);
    for (int i = 0; i < 2; i++) cv.push_back(double2);
    for (int i = 12; i >= 0; i--) if (values[i] == 1) cv.push_back(i);
    return cv;
  } else if (double1 > -1) {
    cv.push_back(1);
    for (int i = 0; i < 2; i++) cv.push_back(double1);
    for (int i = 12; i >= 0; i--) if (values[i] == 1) cv.push_back(i);
    return cv;
  }

  // high card
  cv.push_back(0);
  for (int i = 12; i >= 0; i--) if (values[i] == 1) cv.push_back(i);
  return cv;
}

// returns v0 < v1
// compare val[0], then val[1], then val[2], etc
bool cardless(vector<int> v0, vector<int> v1) { 
  if (v0[0] != v1[0]) return v0[0] < v1[0];
  if (v0[1] != v1[1]) return v0[1] < v1[1];
  if (v0[2] != v1[2]) return v0[2] < v1[2];
  if (v0[3] != v1[3]) return v0[3] < v1[3];
  if (v0[4] != v1[4]) return v0[4] < v1[4];
  return v0[5] < v1[5];
}

int partition(vector<int>& a, vector< vector<int> >& b, int lo, int hi) {
  vector<int> x = b[lo];
  //  printf("x: %d\n", x);
  while (lo <= hi) {
    while (cardless(b[lo], x)) lo++;
    while (cardless(x, b[hi])) hi--;
    //    printf("lo: %d\t hi: %d\n", lo, hi);
    if (lo <= hi) {
      swap(a[lo], a[hi]);
      vector<int> b1 = b[lo];
      b[lo] = b[hi];
      b[hi] = b1;
      lo++;
      hi--;
    }
  }
  //  printf("lo: %d\t hi: %d\n", lo, hi);
  return lo;
}

void qs(vector<int>& a, vector< vector<int> >& b, int lo, int hi) {
  if (lo < hi) {
    int m = partition(a, b, lo, hi);
    qs(a, b, lo, m - 1);
    qs(a, b, m, hi);
  }
}

void pokersort(vector<int>& a) {
  vector< vector<int> > b;
  for (int i = 0; i < a.size(); i++) {
    vector<int> c = val(a[i]);
    for (int j = 0; j < 6; j++) printf("c[%d]: %d \t", j, c[j]);
    cout << "\n";
    b.push_back(c);
  }
  qs(a, b, 0, a.size() - 1);
}

void test(int p, int m) {
  vector<int> a;
  for (int i=p; i<m; ++i) {
    for (int j=p; j<m; ++j){
      for (int k=p; k<m; ++k){
	for (int l=p; l<m; ++l){
	  for (int n=p; n<m; ++n){
	    if(i == j && j == k && k == l && l == n) continue;
	    a.push_back((i * 4)+(52*j*4)+(52*52*k*4)+(52*52*52*l*4)+(52*52*52*52*n*4));
	    // cout << "t";
	  }
	}
      }
    }
  }
  double start=time();
  pokersort(a);
  double end=time();
  cout << end-start << " seconds" << endl;
}

int main() {
  vector<int> hands;
  hands.push_back(29673748);  // 4kind (7) 0 0 0 0 1
  hands.push_back(118694992);  // straightflush (8) 4 3 2 1 0
  hands.push_back(328165340);  // 4kind (7) 11 11 11 11 12
  hands.push_back(37125972);  // fullhouse (6) 0 0 0 1 1
  hands.push_back(296737480);   // highcard (0) 10 7 5 2 0
  hands.push_back(73830068);  // 2pair (2) 1 1 0 0 2
  hands.push_back(146237);  // 3kind (3) 0 0 0 3 1
  hands.push_back(73873332);  // 2kind (1) 0 0 5 2 1
  hands.push_back(118835652);  // straight (4) 4 3 2 1 0
  hands.push_back(354386448);  // flush (5) 12 6 5 1 0
  hands.push_back(59060820);  // 3kind (3) 0 0 0 2 1
  hands.push_back(88869716);  // 3kind (3) 0 0 0 3 2
  hands.push_back(118116180);  // 3kind (3) 0 0 0 4 2
  hands.push_back(118678612);  // 3kind (3) 0 0 0 4 3
  hands.push_back(118689640);  // 3kind (3) 1 1 1 4 3
  hands.push_back(147936104);  // 3kind (3) 1 1 1 5 3
  hands.push_back(176620136);  // 3kind (3) 1 1 1 6 2
  hands.push_back(88880744);  // 3kind (3) 1 1 1 3 2

  for (int i = 0; i < hands.size(); i++) cout << val(hands[i])[0] << " ";
  cout << "\n";

  double start=time();  
  pokersort(hands);
  double end=time();

  for (int i = 0; i < hands.size(); i++) cout << hands[i] << " ";
  cout << "\n";
  for (int i = 0; i < hands.size(); i++) cout << val(hands[i])[0] << " ";
  cout << "\n";
  cout << end-start << " seconds" << endl;

  //  test(0, 10);

  return 0;
}
