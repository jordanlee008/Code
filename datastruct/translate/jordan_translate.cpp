#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int num_trans, num_test;
vector< vector<string> > test;
vector< vector<int> > trans (26, vector<int> (0,0));
vector< vector<int> > fulltrans(26, vector<int> (26, 0));

void filltrans(int x) {
  queue<int> q;
  for (int i : trans[x]) q.push(i);
  while (!q.empty()) {
    int y = q.front();
    q.pop();
    
    for (int i : trans[y]) {
      if (!fulltrans[x][i]) {
	//cout << x << " " << i << "\n";
	q.push(i);
	fulltrans[x][i] = 1;
      }
    }
  }
}

bool cantrans(string a, string b) {
  if (a.length() != b.length()) {
    //printf("length doesn't match\n");
    return false;
  }
  for (int i = 0; i < a.length(); i++) {
    if (!fulltrans[a[i] - 'a'][b[i] - 'a']) {
      //printf("%s, %s\t %c, %c\n", a.c_str(), b.c_str(), a[i], b[i]);
      //printf("%d, %d, %d\n", a[i] - 'a', b[i] - 'a', fulltrans[a[i] - 'a'][b[i] - 'a']);
      return false;
    }
  }
  return true;
}

/*int main() {
  ifstream fin ("translate.in");
  ofstream fout ("translate.out");
  
  cin >> num_trans >> num_test;
  for (int i = 0; i < num_trans; i++) {
    char a, b;
    cin >> a >> b;
    trans[a - 'a'].push_back(b - 'a');
    fulltrans[a - 'a'][b - 'a'] = 1;
  }
  for (int i = 0; i < 26; i++) fulltrans[i][i] = 1;
  for (int i = 0; i < num_test; i++) {
    string a, b;
    cin >> a >> b;
    vector<string> x;
    x.push_back(a);
    x.push_back(b);
    test.push_back(x);
  }
  
  for (int i = 0; i < 26; i++) filltrans(i);
  
for (int i = 0; i < 26; i++) {
    cout << i << " ";
    for (int j = 0; j < 26; j++) {
      cout << fulltrans[i][j] << " ";
    }
    cout << "\n";
    }

  
  for (int i = 0; i < num_test; i++) {
    if (cantrans(test[i][0], test[i][1])) cout << "yes\n";
    else cout << "no\n";
  }
  
  return 0;
}*/
