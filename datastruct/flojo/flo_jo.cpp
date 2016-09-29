#include "Link.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> loopTail(Link<int>* head) {
  Link<int> *f = head; // fast pointer
  Link<int> *s = head; // slow pointer
  
  int i = 0;
  while (f->next) {
    // we shall move s after f has moved twice
    f = f->next;
    if (i % 2)
      s = s->next;
    i++;
    
    if (f == s) { // cycle found
      vector<int> o; // output vector
      // find the length of the cycle
      int j = 0;
      do {
	j++;
	f = f->next;
      } while (f != s);
      o.push_back(j);
      
      // find the length of the tail
      f = head;
      s = head;
      for (int k = 0; k < j; k++)
	f = f->next;
      int k = 0;
      while (f != s) {
	k++;
	f = f->next;
	s = s->next;
      }
      o.push_back(k);
      return o;
    }
  } // if this loop breaks there is an end to the list (no loop)
  
  cout << "no cycle found" << endl;
  vector<int> o;
  o.push_back(0);
  o.push_back(++i);
  return o;
}

vector<int> josephus(int n, int k) {
  if (!n) {
    vector<int> v;
    return v;
  }

  // create loop linked list
  Link<int> *p = new Link<int>(n--);
  Link<int> *l = p;
  while (n) {
    p = new Link<int>(n--, p);
  }
  l->next = p;
  // l points to the last link (containing value n)
  // p points to the first link (containing value 1)
  
  
  int i = 1; // counter to detect to kill
  vector<int> o; // output vector
  
  while (p->next != p) {
    if (i % k == 0) {
      o.push_back(p->info);
      l->next = p->next;
      p = l->next;
    } else {
      p = p->next;
      l = l->next;
    }
    i++;
  }
  o.push_back(p->info);
  return o;
}

/* int main() {
  // test josephus
  cout << "Please input n then k for josephus" << endl;
  int n, k;
  cin >> n >> k;
  vector<int> v1 = josephus(n, k);
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << " ";
  cout << endl;
  
  // test loopTail
  cout << "Please input the length of the tail" << endl;
  cout << "Then input the length of the loop" << endl;
  int t, l;
  cin >> t >> l;
  Link<int> *current = 0;
  if (l) {
    Link<int> *end = new Link<int>(0, current);
    current = end;
    for (int i = 0; i < l - 1; i++) {
      current = new Link<int>(i, current);
    }
    end->next = current;
  }
  for (int i = 0; i < t; i++) {
    current = new Link<int>(i, current);
  }

  vector<int> v2 = loopTail(current);
  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";
  cout << endl;
 } */

