#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct disc {
  string id; // id
  int w; // weight;
  int tw; // total weight + itself
  disc *p; // parent disc
  bool bad;
  
  vector<string> ci; // children id
  vector<disc*> c; // children pointers
  
  bool operator< (const disc& d_o) const { return (id < d_o.id); }
};

int find_root(vector<string> &all_c, vector<string> &all_id) {
  // PART 1
  sort(all_c.begin(), all_c.end());
  sort(all_id.begin(), all_id.end());
  /*  cout << all_id.size() << " " << all_c.size() << "\n";
  for (int i = 0; i < all_id.size(); i++) {
    cout << name_inv(all_id[i]) << " ";
  } cout << "\n";
  for (int i = 0; i < all_c.size(); i++) {
    cout << name_inv(all_c[i]) << " ";
  } cout << "\n"; */
  int root = -1;
  for (int i = 0; i < all_c.size(); i++) {
    if (all_id[i] != all_c[i]) {
      root = i;
      break;
    }
  }
  if (root == -1) root = all_id.size()-1;
  return root;
}

int build(int root, vector<disc> &d) {
  // PART 2 - DFS to fill weights
  int tw = 0; // total weight holding (+ itself)
  int nc = d[root].ci.size();
  for (int i = 0; i < nc; i++) {
    for (int k = 0; k < d.size(); k++) {
      if (d[k].id == d[root].ci[i]) {
	d[root].c.push_back(&d[k]);
	d[k].p = &d[root];
	tw += build(k,d);
	break;
      }
    }
  }
  bool b = false;
  if (nc) {
    for (int i = 0; i < nc; i++) {
      if (d[root].c[i]->tw != tw/nc) b = true;
    }
  }
  d[root].bad = b;
  
  tw += d[root].w;
  d[root].tw = tw;

  return tw;
}

disc* find_bad(disc* d) {
  //  cout << d->id << "\n";
  for (int i = 0; i < d->c.size(); i++) {
    if (d->c[i]->bad) {
      return find_bad(d->c[i]);
    }
  }
  return d;
}

int main () {
  ifstream fin ("balance.in");
  ofstream fout ("balance.out");
  
  vector<disc> d; // all discs
  vector<string> all_id; // all ids
  vector<string> all_c; // all children
  
  string s;
  while (getline(fin, s)) {
    disc d0;
    d0.id = s.substr(0, s.find(" "));
    all_id.push_back(d0.id);
    d0.w = atoi(s.substr(s.find("(")+1, s.find(")")).c_str());
    
    vector<string> c0;
    string s0;
    if (s.find("-> ") != string::npos) {
      for (int i = s.find("-> ") + 3; i < s.length(); i++) {
	if (s[i] == ' ') { }
	else if (s[i] == ',') {
	  c0.push_back(s0);
	  all_c.push_back(s0);
	  s0 = "";
	}
	else { s0 += s[i]; }
      }
      c0.push_back(s0);
      all_c.push_back(s0);
    }
    d0.ci = c0;
    d.push_back(d0);
  }
  // CHECK DATA
  /*  for (int i = 0; i < d.size(); i++) {
    cout << d[i].id << " " << d[i].w << "\n";
    for (int k = 0; k < d[i].c.size(); k++) cout << d[i].c[k] << " ";
    cout << "\n";
    }*/
  
  // PART 1
  int root = find_root(all_c, all_id);
  fout << "root " <<  all_id[root] << "\n";
  
  // PART 2
  // build tree
  sort(d.begin(), d.end());
  int tw = build(root, d);

  /*  for (int i = 0; i < d.size(); i++)
      if (d[i].bad) cout << d[i].id << "\n";*/

  // find bad guy
  disc* bd = find_bad(&d[root]); // parent of bad guy
  disc* bad;
  int w1 = bd->c[0]->tw, w2, n2 = 0, ind;
  for (int i = 0; i < bd->c.size(); i++) {
    //    cout << bd->c[i]->id << " " << bd->c[i]->tw << "\n";
    if (bd->c[i]->tw != w1) {
      ind = i;
      n2++;
      w2 = bd->c[i]->tw;
    }
  }
  if (n2 > 1) {
    bad = bd->c[0];
    fout << bad->w + (w2 - w1) << "\n";
  }
  else {
    bad = bd->c[ind];
    fout << bad->w + (w1 - w2);
  }
  fout << "bad " << bad->id << "\n";

  return 0;
}
