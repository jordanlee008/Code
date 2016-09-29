/*
ID: jorlee
PROG: lightson
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, M;
vector<int> lit; //WHAT ROOMS ARE LIT
//so adj[a,b] = x,y means i can go from a,b to x,y
vector< vector<int> > lights; //WHAT ROOMS HAVE WHAT LIGHTSWITCH
//so lights[a,b] holds all the rooms that can be lit from a,b


void lightup (int x) {
  for (int i = 0; i < lights[x].size(); i++) {
    lit[lights[x][i]] = 1;
    printf("cell %d now lit\n", lights[x][i]);
  }
}

int main () {
  ofstream fout ("lightson.out");
  ifstream fin ("lightson.in");
  
  fin >> N >> M;

  cout << N << " " << M << endl;
  
  for (int i = 0; i < N*N; i++) {
    lit.push_back(0);
    lights.push_back(vector<int> ());
  }
  
  //  printf("reading lights");
  for (int i = 0; i < M; i++) {
    int x,y,a,b;
    fin >> x >> y >> a >> b;
    //    fout << x << y << a << b;
    lights[(x-1) + N * (y-1)].push_back((a-1) + N * (b-1));
  }

  //  for (int i = 0; i < N*N; i++)
  //for (int j = 0; j < lights[i].size(); j++)
  //  printf("lights[%d][%d] = %d\n", i, j, lights[i][j]);

  //  printf("init vectors\n");
  lit[0] = 1;

  vector<int> boundary;
  boundary.push_back(0);

  vector<bool> visited;
  for (int i = 0; i < N*N; i++) {
    visited.push_back(false);
  }

  bool loop = true;
  while (loop) {

    loop = false;
    for (int i = 0; i < boundary.size(); i++) {
      int cell = boundary[i];
      //      printf("checking cell %d\n", cell);
      if((lit[cell]) && (!visited[cell])) {
	loop = true;
	printf("cell %d is lit\n", cell);
	lightup(cell);
	visited[cell] = true;
	
	int ycell = cell / N;
	int xcell = cell % N;
      
	int neighbor;

	neighbor = cell + N;
	if ((ycell < N - 1) && (!visited[neighbor])) {
	  boundary.push_back(neighbor);
	  //	  printf("cell %d pushed\n", neighbor);
	}
	
	neighbor = cell - N;
	if ((ycell > 0) && (!visited[neighbor])) {
	  boundary.push_back(neighbor);
	  //	  printf("cell %d pushed\n", neighbor);
	}
	
	neighbor = cell + 1;
	if ((xcell < (N - 1)) && !visited[neighbor]) {
	  boundary.push_back(neighbor);
	  //	  printf("cell %d pushed\n", neighbor);
	}
	
	neighbor = cell - 1;
	if ((xcell > 0) && (!visited[neighbor])) {
	  boundary.push_back(neighbor);
	  //	  printf("cell %d pushed\n", neighbor);
	}
	
	for (int j = i + 1; j < boundary.size(); j++) {
	  boundary[j - 1] = boundary[j];
	  //	  printf("boundary[%d] = %d\n", j - 1, boundary[j]);
	}
	boundary.pop_back();
	break;
      }
    }
  }

  int count = 0;
  for (int i = 0; i < N*N; i++)
    if (lit[i])
      count++;
  fout << count << endl;
  
  
  return 0;
}
