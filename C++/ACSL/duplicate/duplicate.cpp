/*
   Jordan Lee
   Bergen County Academies
   5-Person Senior Division
 */

#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

struct node {
  node(char c, int n=1) : c(c), n(n) {}

  char c;
  int n;
  node* l = 0;
  node* r = 0;
};

void ins(node* root, char c0) {
  if (c0 == (root->c)) {
    root->n++;
    return;
  }
  
  if (c0 < (root->c)) {
    if ((!root->l)) {
      root->l = new node(c0);
      return;
    } else {
      ins(root->l, c0);
    }
  } 
  if (c0 > (root->c)) {
    if (!(root->r)) {
      root->r = new node(c0);
      return;
    } else {
      ins(root->r, c0);
    }
  }
}

int main() {
  ifstream fin ("c_4_duplicates_sr_sample.txt");
  ofstream fout ("");
  
  for (int i = 0; i < 5; i++) {
    node* root = 0;
    string s;
    getline(fin,s);
    for (int j = 0; j < s.length(); j++) {
      char c;
      if (s[j] < 123 && s[j] > 96) c = s[j] - 'a' + 'A';
      else if (s[j] < 91 && s[j] > 64) c = s[j];
      else continue;
      
      if (root == 0) root = new node(c);
      else ins(root,c);
    }
    
    int tot = 0;
    deque<node*> d;
    d.push_back(root);
    while (!d.empty()) {
      node* n0 = d.front();
      d.pop_front();
      if ((!n0->l && n0->r) || (!n0->r && n0->l)) {
	tot += n0->n;
      }
      if (n0->l) d.push_back(n0->l);
      if (n0->r) d.push_back(n0->r);
    }
    cout << tot << "\n";
  }
}
