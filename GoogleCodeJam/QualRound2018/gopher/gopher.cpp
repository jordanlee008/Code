#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int A;
    cin >> A;

    int s1 = 1, s2 = 1;
    while (s1*s1 < A) {
      s1++;
    }
    if (s1*s1 == A) {
      s2 = s1;
    } else {
      s2 = s1-1;
      while (s1*s2 < A) {
	s1++;
      }
    }
    //printf("%d %d\n", s1, s2);
    
    vector< vector<int> > b (s1 + 4, vector<int>(s2 + 4,0));
    bool done = false;
    for (int r = 2; r < s1 && !done; r++) {
      for (int c = 2; c < s2 && !done; c++) {
	while (b[r][c] == 0 && !done) {
	  printf("%d %d\n",r,c);
	  int x1,x2;
	  cin >> x1 >> x2;
	  
	  if (x1 == -1 && x2 == -1) return 0;
	  else if (x1 == 0 && x2 == 0) { done = true; break; }
	  else b[x1][x2] = 1;
	}
      }
    }
    
    for (int c = 2; c < s2 && !done; c++) {
      while (b[1][c] == 0 && !done) {
	printf("%d %d\n",2,c);
	int x1,x2;
	cin >> x1 >> x2;
	
	if (x1 == -1 && x2 == -1) return 0;
	if (x1 == 0 && x2 == 0) { done = true; break; }
	b[x1][x2] = 1;
      }
      while (b[s1][c] == 0 && !done) {
	printf("%d %d\n",s1-1,c);
	int x1,x2;
	cin >> x1 >> x2;
	
	if (x1 == -1 && x2 == -1) return 0;
	if (x1 == 0 && x2 == 0) { done = true; break; }
	b[x1][x2] = 1;
      }
    }

    for (int r = 2; r < s1 && !done; r++) {
      while (b[r][1] == 0 && !done) {
	printf("%d %d\n",r,2);
	int x1,x2;
	cin >> x1 >> x2;
	
	if (x1 == -1 && x2 == -1) return 0;
	if (x1 == 0 && x2 == 0) { done = true; break; }
	b[x1][x2] = 1;
      }
      while (b[r][s2] == 0 && !done) {
	printf("%d %d\n",r,s2-1);
	int x1,x2;
	cin >> x1 >> x2;
	
	if (x1 == -1 && x2 == -1) return 0;
	if (x1 == 0 && x2 == 0) { done = true; break; }
	b[x1][x2] = 1;
      }
    }

    while (b[1][1] == 0 && !done) {
      printf("2 2\n");
      int x1,x2;
      cin >> x1 >> x2;
	
      if (x1 == -1 && x2 == -1) return 0;
      if (x1 == 0 && x2 == 0) { done = true; break; }
      b[x1][x2] = 1;
    }

    while (b[1][s2] == 0 && !done) {
      printf("2 %d\n", s2-1);
      int x1,x2;
      cin >> x1 >> x2;
	
      if (x1 == -1 && x2 == -1) return 0;
      if (x1 == 0 && x2 == 0) { done = true; break; }
      b[x1][x2] = 1;
    }
    
    while (b[s1][1] == 0 && !done) {
      printf("%d 2\n", s1-1);
      int x1,x2;
      cin >> x1 >> x2;
	
      if (x1 == -1 && x2 == -1) return 0;
      if (x1 == 0 && x2 == 0) { done = true; break; }
      b[x1][x2] = 1;
    }
    
    while (b[s1][s2] == 0 && !done) {
      printf("%d %d\n", s1-1,s2-1);
      int x1,x2;
      cin >> x1 >> x2;
      
      if (x1 == -1 && x2 == -1) return 0;
      if (x1 == 0 && x2 == 0) { done = true; break; }
      b[x1][x2] = 1;
    }
    
  }
}
