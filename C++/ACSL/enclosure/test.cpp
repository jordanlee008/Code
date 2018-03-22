#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  freopen("big.txt", "w", stdout);

  vector<char> parena{'(', '{', '['}, parenb{')', '}', ']'}, symb{'+', '-', '*', '/'};
  int n = 3;
  int parf  = 15;
  int freq = 2;

  for (int tst = 0; tst < 50; tst++) {
    vector<int> l{0, 1, 2};
    stack<int> st, st2;
    for (int i = 0; i < n; i++) {
      int r = rand() % l.size();
      st.push(l[r]);
      l.erase(l.begin() + r);
    }

    bool num, sb, deleted;
    num = sb = deleted = 0;
    string s = "";
    while(st.size() || st2.size()) {
      int add = rand() % parf, rem = rand() % parf, sym = rand() % freq;
      if (st.size() && sb && add == 0) {
        if (rand() % n == 0 && !deleted)
          deleted = true;
        else
          s += parena[st.top()];
        st2.push(st.top());
        st.pop();
        num = 0;
        sb = 0;
      }

      if (sym == 0 && num) {
        int x = rand() % 4;
        s += symb[x];
        sb = 1;
        num = 0;
      } else if (sym && rand() % 3 != 0) {
        s += (char)(rand() % 10 + '0');
        num = 1;
      }

      if (st2.size() && rem == 0 && num && sb) {
        if (rand() % n == 0 && !deleted)
          deleted = true;
        else
          s += parenb[st2.top()];
        st2.pop();
        num = 0;
        sb = 0;
      }
    }

    if (!deleted)
      for (int i = 0; i < s.size(); i++)
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
          string t = s;
          s = t.substr(0, i) + t.substr(i + 1);
          break;
        }
    if (s.size() < 100)
      tst--;
    else
      cout << s << "\n";
  }

  return 0;
}
