#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(const int val, int depth = 0, Node* l = 0, Node* r = 0) : val(val), depth(depth), l(l), r(r) { }
  Node(const Node& n) {
    l = n.l;
    r = n.r;
    val = n.val;
  }
  
  Node* insert(int x) {
    if (x <= val)
      return (l? l->insert(x) : l = new Node(x, depth+1));
    else
      return (r? r->insert(x) : r = new Node(x, depth+1));
  }
  Node* l;
  Node* r;
  Node* parent;
  int val;
  int depth;
};

int finddepth(Node *root) {
  int l = root->depth, r = root->depth;
  if (root->l) l = finddepth(root->l);
  if (root->r) r = finddepth(root->r);
  
  return max(l, r);
}

int findleaf(Node *root) {
  int l = 0, r = 0;
  if (root->l) l = findleaf(root->l);
  if (root->r) r = findleaf(root->r);
  if (root->r == 0 && root->l == 0) return 1;
  return l + r;
}

int findchina(Node *root) {
  int l = 0, r = 0, x = 0;
  if (root->l) l = findchina(root->l);
  if (root->r) r = findchina(root->r);
  if ((root->l == 0 && root->r != 0) || (root->l != 0 && root->r == 0)) x = 1;
  return l + r + x;
}

int findinternal(Node *root) {
  int l = 0, r = 0;
  if (root->l) l = findinternal(root->l);
  if (root->r) r = findinternal(root->r);
  return l + r + root->depth;
}

int findexternal(Node *root) {
  int l = 0, r = 0, x = 0;
  if (root->l) l = findexternal(root->l);
  if (root->r) r = findexternal(root->r);
  if (!root->l) x += root->depth + 1;
  if (!root->r) x += root->depth + 1;
  return l + r + x;
}

string filter(string s) {
  string ns;
  for (int i = 0; i < s.size(); i++) {
    if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) ns += s[i];
  }
  return ns;
}

int main() {
  for (int i = 0; i < 2; i++) {
    try {
      char word[128] = {};
      string s;
      cin.getline(word, 128);
      for (int j = 0; j < 128; j++) {
	if (word[j] != ' ') s += word[j];
      }
      s = filter(s);
      //      cout << s << "\n";
      
      bool getroot = true;
      Node *root = 0;
      for (int i = 0; i < s.size(); i++) {
	if (getroot) {
	    root = new Node((int) s[0]);
	    getroot = false;
	} else {
	  root->insert(s[i]);
	}
      }
      cout << 5*i + 1 << ". " << finddepth(root) << "\n";
      cout << 5*i + 2 << ". " << findleaf(root) << "\n";
      cout << 5*i + 3 << ". " << findchina(root) << "\n";
      cout << 5*i + 4 << ". " << findinternal(root) << "\n";
      cout << 5*i + 5 << ". " << findexternal(root) << "\n";
    } catch (exception e) {
      cout << "ERROR\n";
    }

  }
}
