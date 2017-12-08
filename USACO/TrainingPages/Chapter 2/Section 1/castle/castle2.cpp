/*
  ID: jorlee
  PROG: castle
  LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/* flood fill for listing rooms:
 * iterate through all cells
 * look at neighbors, label those as the same room
 * keep iterating until no unvisited neighbors */

int length, width;
int wall[50][50];
vector< vector<int> > adj(250);
vector<int> room(250);
int nroom;

vector<int> countwall(int n) {
  vector<int> ret(4);
  for (int i = 3; i >= 0; i--) { //iterate through all digits
    int k = 1;
    for (int l = 0; l < i; l++) //exponentiation
      k = 2 * k;
    if (n >= k) {
      ret[i] = 1;
      n = n - k;
    }
  }
  return ret; //returns such that ret[i] = 2^i place... so ret[0] = 1's digit
}

void filladj(vector<int> n, int pos) {
  if (!n[0])
    adj[pos].push_back(pos - 1);
  if (!n[1])
    adj[pos].push_back(pos - width);
  if (!n[2])
    adj[pos].push_back(pos + 1);
  if (!n[3])
    adj[pos].push_back(pos + width);
}

void fillroom(vector<int> nadj, int i, int croom) {
  room[i] = croom;
  for (int j = 0; j < nadj.size(); j++)
    if (room[nadj[j]] == 0)
      fillroom(adj[nadj[j]], nadj[j], croom);
}

int main(void) {
  ifstream fin ("castle.in");
  ofstream fout ("castle.out");

  fin >> width >> length;
  for (int i = 0; i < length; i++)
    for (int j = 0; j < width; j++) {
      fin >> wall[i][j];
      vector<int> w = countwall(wall[i][j]);
      for (int k = 0; k < 4; k++)
	cout << w[k];
      cout << endl;
    }

  //fills out adjacency list of cells
  for (int i = 0; i < length; i++)
    for (int j = 0; j < width; j++) {
      vector<int> w = countwall(wall[i][j]);
      filladj(w, i * width + j);
    }
  /*  for (int i = 0; i < width*length; i++) {
      for (int j = 0; j < adj[i].size(); j++)
      cout << adj[i][j] << " ";
      cout << endl;
      } */

  //flood fill in order to put together the cells into numbered rooms
  nroom = 0;
  for (int i = 0; i < length * width; i++) {
    if (room[i] == 0) {
      nroom++;
      fillroom(adj[i], i, nroom);
    }
  }
  cout << "number of rooms: " << nroom << endl;
  fout << nroom << endl;

  //counts the biggest room
  vector<int> rsize(nroom);
  for (int i = 0; i < length*width; i++)
    rsize[room[i]]++;
  int max = 0;
  for (int i = 0; i < rsize.size(); i++) {
    if (rsize[i] > max)
      max = rsize[i];
  }
  cout << max << endl;
  fout << max << endl;

  //iterate through removing all walls (starting from north west going south
  //then east) and find the biggest room
  int maxsize = 0; //variables to save data
  int x, y;    //for output
  char ne;

  //delete north adjacency and rooms again
  for (int xcoord = 0; xcoord < width; xcoord++) {
    for (int ycoord = 0; ycoord < length; ycoord++) {

      //WRITE CODE TO DELETE NORTH ADJACENCY
      //AND DELETE ROOMS
      
      
      //then redo floodfill to check for total rooms
      nroom = 0;
      for (int i = 0; i < length * width; i++) {
	if (room[i] == 0) {
	  nroom++;
	  fillroom(adj[i], i, nroom);
	}
      }
  
      //recheck for biggest room
      vector<int> remsize(nroom);
      for (int i = 0; i < length*width; i++)
	remsize[room[i]]++;
      int remmax = 0;
      for (int i = 0; i < remsize.size(); i++) {
	if (remsize[i] > remmax)
	  remmax = remsize[i];
	if (remmax > maxsize) {
	  maxsize = remmax;
	  y = (i / length) + 1;
	  x = i + length - (length * y) + 1;
	  ne = 'N';
	}
      }

    }
  }

  //COPY NORTH CODE BUT DO EAST WALL


  fout << x << " " << y << " " << ne << endl;
  
  return 0;
}
