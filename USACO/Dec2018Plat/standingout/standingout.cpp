#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ifstream fin ("standingout.in");
  ofstream fout ("standingout.out");
  
  long long int N;
  fin >> N;

  long long int t = 0;
  unordered_map<string, long long int> m;
  vector<long long int> uniq;
  vector<long long int> found;
  
  for (long long int i = 0; i < N; i++) {
    string s;
    fin >> s;
    //    cout << s << " " << s.length() << "\n";
    
    long long int sv;
    if (m.find(s) == m.end()) {
      sv = t;
      m.emplace(s, t);
      t++;
      found.push_back(-1);
    } else {
      sv = m.find(s)->second;
    }
    uniq.push_back(0);
    
    for (long long int j = 0; j < s.length(); j++) {
      for (long long int k = 1; k < s.length() + 1 - j; k++) {
	//	cout << j << " " << k;
	string ss = s.substr(j, k);
	//	cout <<  " " << ss << "\n";
	
	long long int ssv;
	if (m.find(ss) == m.end()) {
	  ssv = t;
	  m.emplace(ss, t);
	  t++;
	  found.push_back(-1);
	} else {
	  ssv = m.find(ss)->second;
	}

	if (found[ssv] == -1) {
	  uniq[i]++;
	  found[ssv] = i;
	}
	else if (found[ssv] != -1 && found[ssv] != -2 && found[ssv] != i) {
	  uniq[found[ssv]]--;
	  found[ssv] = -2;
	}
	

      }
    }
  }
  
  for (long long int i = 0; i < uniq.size(); i++) {
    fout << uniq[i] << "\n";
  }
  
}
