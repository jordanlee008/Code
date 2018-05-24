#include <iostream>
#include <vector>

using namespace std;

int containPU(string s) {
  int counter = 0;
  for (int i = 0; i < s.size(); ++i) counter++;
  return counter;
}

string convert(string s) {
  string out = "";
  for (int i = 0; i < s.size()-1; ++i) {
    if (s[i+1] == '*') {
      if (s[i] == 'a') out += "c";
      else out += "d";
      i++;
    }
    else out += s[i];
  }
  return out;
}

string defAdd(char ch) {
  if (ch == 'a') return "-aO";
  if (ch == 'b') return "-bO";
  if (ch == 'c') return "a*";
  if (ch == 'd') return "b*";
}

string endAdd(char ch) {
  if (ch == 'a') return "-a\t@";
  if (ch == 'b') return "-b\t@";
  if (ch == 'c') return "a*\t@";
  if (ch == 'd') return "b*\t@";
}

string unStartAdd(char ch) {
  if (ch == 'a') return "aO";
  if (ch == 'b') return "bO";
  if (ch == 'c') return "a*";
  if (ch == 'd') return "b*";
}

string unEndAdd(char ch) {
  if (ch == 'a') return "a";
  if (ch == 'b') return "b";
  if (ch == 'c') return "a*";
  if (ch == 'd') return "b*";
}



int main() {
  vector<string> inputs(10);
  for (int i = 0; i < 10; ++i)
    cin >> inputs[i];

  for (int i = 0; i < 10; ++i) {
    string input = convert(inputs[i]);
    int contain = containPU(input);
    if (contain % 2 == 1) {
      vector<string> out(3);
      out[0] = "\t";
      out[1] = "O\t";
      out[2] = "\t";
      int scanned = 0;

      if (contain > 1) {
	while (input[scanned] != '(') {
	  out[0] += "\t";
	  out[2] += "\t";
	  out[1] +=  defAdd(input[scanned]) + "\t";
	  scanned++;
	}

	scanned++; // accounts for '('

	//-----union add--------
	string s1 = "";
	string s2 = "";
	
	while (input[scanned+1] != "U") {
	  s1 += input[scanned];
	  scanned++;
	}

	scanned++; // accounts for 'U'

	while (input[scanned+1] != ")") {
	  s2 += input[scanned];
	  scanned++;
	}
	int length = (s1.size() >= s2.size()) ? s1.size() : s2.size();

	out[0] += unStartAdd(s1[0]) + "\t";
	out[2] += unStartAdd(s2[0]) + "\t";

	for (int uni = 1; i < length-1; ++i) {
	  if (uni+2 == s1.size()) out[0] += "\t";
	  else out[0] += defAdd(s1[uni]) + "\t";
	  if (uni+2 == s2.size()) out[2] += "\t";
	  else out[2] += defAdd(s2[uni]) + "\t";
	}

	out[0] += unEndAdd(s1[s1.size()-1]) + "\t";
	out[2] += unEndAdd(s2[s2.size()-1]) + "\t";
	
	// end union add
	
	scanned++; // accounts for ')'
      }

      int scanned = 0;
	string s1 = "";
	string s2 = "";
	
	while (input[scanned+1] != "U") {
	  s1 += input[scanned];
	  scanned++;
	}

	scanned++; // accounts for 'U'

	while (input[scanned+1] != ")") {
	  s2 += input[scanned];
	  scanned++;
	}
	int length = (s1.size() >= s2.size()) ? s1.size() : s2.size();

	out[0] += unStartAdd(s1[0]) + "\t";
	out[2] += unStartAdd(s2[0]) + "\t";

	for (int uni = 1; i < length-1; ++i) {
	  if (uni+2 == s1.size()) out[0] += "\t";
	  else out[0] += defAdd(s1[uni]) + "\t";
	  if (uni+2 == s2.size()) out[2] += "\t";
	  else out[2] += defAdd(s2[uni]) + "\t";
	}

	out[0] += unEndAdd(s1[s1.size()-1]) + "\t";
	out[2] += unEndAdd(s2[s2.size()-1]) + "\t";
      //-----union add-------
    }
    else {
      string out = "O\t"
      for (int j = 0; j < input.size()-1; j++)
	cout << defAdd(input[j]) << "\t";
      cout << endAdd(input[input.size()-1]) << endl;
    }
  }
  
}
