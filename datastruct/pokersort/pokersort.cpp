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
    for (int i = 1; i <= 5; i++) cv.push_back(index - i);
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

// returns h0 < h1
// compare val[0], then val[1], then val[2], etc
bool cardless(int h0, int h1) { 
  vector<int> v0 = val(h0), v1 = val(h1);
  if (v0[0] != v1[0]) return v0[0] < v1[0];
  if (v0[1] != v1[1]) return v0[1] < v1[1];
  if (v0[2] != v1[2]) return v0[2] < v1[2];
  if (v0[3] != v1[3]) return v0[3] < v1[3];
  if (v0[4] != v1[4]) return v0[4] < v1[4];
  return v0[5] < v1[5];
}

int partition(vector<int>& a, int lo, int hi) {
  int x = a[lo];
  //  printf("x: %d\n", x);
  while (lo <= hi) {
    while (cardless(a[lo], x)) lo++;
    while (cardless(x, a[hi])) hi--;
    //    printf("lo: %d\t hi: %d\n", lo, hi);
    if (lo <= hi) {
      int b = a[lo];
      a[lo++] = a[hi];
      a[hi--] = b;
    }
  }
  //  printf("lo: %d\t hi: %d\n", lo, hi);
  return lo;
}

void qs(vector<int>& a, int lo, int hi) {
  if (lo < hi) {
    //    printf("lo: %d\t hi: %d\n", lo, hi);
    //    printf("a[lo]: %d\n", a[lo]);
    //    printf("a[hi]: %d\n", a[hi]);
    int m = partition(a, lo, hi);
    qs(a, lo, m - 1);
    qs(a, m, hi);
  }
}

void pokersort(vector<int>& a) {
  qs(a, 0, a.size() - 1);
}

int main() {
  // 4kind (7) 0 0 0 0 1
  // straightflush (8) 4 3 2 1 0
  // 4kind (7) 11 11 11 11 12
  // fullhouse (6) 0 0 0 1 1
  // highcard (0) 10 7 5 2 0
  // 2pair (2) 1 1 0 0 2
  // 3kind (3) 0 0 0 1 2
  // 2kind (1) 0 0 5 2 1
  // straight (4) 4 3 2 1 0
  // flush (5) 12 6 5 1 0
  vector<int> hands;
  hands.push_back(29673748);
  hands.push_back(118694992);
  hands.push_back(328165340);
  hands.push_back(37125972);
  hands.push_back(296737480);
  hands.push_back(73830068);
  hands.push_back(73824660);
  hands.push_back(73873332);
  hands.push_back(118835652);
  hands.push_back(354386448);

  /*296737480
    73873332
    73830068
    73824660
    118835652
    354386448
    37125972
    29673748
    328165340
    118694992 */

  double start=time();
  for (int i = 0; i < hands.size(); i++) cout << val(hands[i])[0] << " ";
  cout << "\n";
  
  pokersort(hands);
  //  qs(hands, 0, hands.size() - 1);

  
  double end=time();
  for (int i = 0; i < hands.size(); i++) cout << hands[i] << " ";
  cout << "\n";
  for (int i = 0; i < hands.size(); i++) cout << val(hands[i])[0] << " ";
  cout << "\n";
  cout << end-start << " seconds" << endl;

  return 0;
}
