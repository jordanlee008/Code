/*
ID: jorlee
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int N; //number of elements to be sorted
vector<int> s; //set of elements that need to be sorted
int n1, n2, n3; //number of each type of element respectively
vector<int> s1(3), s2(3), s3(3); //number of each type of element in each section
                        //s1[0] is 1's in 1st section, s1[1] is 1's in 2nd, ...

int main () {
  ifstream fin ("sort3.in");
  ofstream fout ("sort3.out");

  fin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    fin >> x;
    s.push_back(x);
  }
  
  /*
    PLAN OF ACTION:
    1) iterate through set, count number of 1's, 2's, 3's
    2) check to see how many 1's, 2's 3's are in the each section
    3) do math and get the answer
   */
  
  //STEP 1: ITERATE THROUGH SET, COUNTING HOW MANY OF EACH ELEMENT
  for (int i = 0; i < N; i++) {
    if (s[i] == 1)
      n1++;
    else if (s[i] == 2)
      n2++;
    else
      n3++;
  }
  printf("n1: %d\nn2: %d\nn3: %d\n", n1, n2, n3);
  
  //STEP 2: CHECK TO SEE HOW MANY OF EACH ELEMENT ARE IN EACH SECTION
  for (int i = 0; i < n1; i++)
    if (s[i] == 1)
      s1[0]++;
    else if (s[i] == 2)
      s2[0]++;
    else
      s3[0]++;
  
  for (int i = 0; i < n2; i++)
    if (s[n1 + i] == 1)
      s1[1]++;
    else if (s[n1 + i] == 2)
      s2[1]++;
    else
      s3[1]++;
  
  for (int i = 0; i < n3; i++)
    if (s[n1 + n2 + i] == 1)
      s1[2]++;
    else if (s[n1 + n2 + i] == 2)
      s2[2]++;
    else
      s3[2]++;
  
  for (int i = 0; i < 3; i++)
    printf("s1[%d] = %d\n", i, s1[i]);
  for (int i = 0; i < 3; i++)
    printf("s2[%d] = %d\n", i, s2[i]);
  for (int i = 0; i < 3; i++)
    printf("s3[%d] = %d\n", i, s3[i]);
  
  int out = 0;
  int temp;
  //STEP 3: DO MATH
  //first make all 1-move switches between 1's/2's and 1's/3's
  temp = min(s1[1], s2[0]);
  out += temp;
  s1[1] -= temp;
  s1[0] += temp;
  s2[0] -= temp;
  s2[1] += temp;

  cout << "out at 1/2: " << out << endl;

  temp = min(s3[0], s1[2]);
  out += temp;
  s1[2] -= temp;
  s1[0] += temp;
  s3[0] -= temp;
  s3[2] += temp;

  cout << "out at 1/3: " << out << endl;
  
  //make all 1-move switches between 2's/3's
  temp = min(s3[1], s2[2]);
  out += temp;
  s3[1] -= temp;
  s3[2] += temp;
  s2[2] -= temp;
  s2[1] += temp;
  
  cout << "out at 2/3: " << out << endl;
  
  //make all 2-move switches between 1's/2's/3's
  
  out += 2 * (n1 - s1[0]);

  cout << "out at 1/2/3: " << out << endl;
  
  fout << out << endl;
  
  return 0;
}
