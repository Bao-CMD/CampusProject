#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Campus.hpp"

using namespace std;

struct node nodeArray[24];

int main (int argc, char* argv[]) {
  string filename;
  if (argc != 2) {
    cout << "2 arguments are required" << endl;
  } else {
    filename = argv[1];
  }

  ifstream fs;
  fs.open(filename);

  string line = "";
  string name;
  string y;
  string x;
  int arraySize = 24;
  int i = 0;

  // node* array[arraySize];

  if (fs.is_open())
  {
    while (!fs.eof())
    {
      // while(getline(fs,line)){
      getline(fs, line);
      istringstream ss(line);

      getline(ss, name, ',');
      getline(ss, x, ',');
      float dX = stof(x);
      getline(ss, y);
      float dY = stof(y);

      //Adding item to array
      nodeArray[i].addElement(name, dX, dY);
      // cout << "Index: " << i << endl;
      // cout << "\t" << nodeArray[i].name << endl;
      // cout << "\t" << nodeArray[i].distanceX << endl;
      // cout << "\t" << nodeArray[i].distanceY << endl;
      i++;
      // // }
    }
  }

  // //Printing array function
  // for (int i = 0; i < 24; i++)
  // {
  //   cout << "Index: " << i << endl;
  //   cout << "\tString name - " << nodeArray[i].name << endl;
  //   cout << "\tDistance X - " << nodeArray[i].distanceX << endl;
  //   cout << "\tDistance Y - " << nodeArray[i].distanceY << endl;
  // }

  // //Testing printing with nested loop
  // for (int a = 0; a < 10; a++) {
  //   for (int b = a+1; b < 10; b++) {
  //     cout << a << "and" << b << endl;
  //   }
  // }

  //Creat graph and add edges
  graph g;
  //Creating vertices
  for (int i = 0; i < 24; i++) {
    g.addVertex(nodeArray[i].name);
  }

  // //Printing list of verticies
  // g.printVertices();

  //Adding edges
  for (int j = 0; j < 24; j++) {
    for (int k = j+1; k < 24; k++) {
      node v1 = nodeArray[j];
      node v2 = nodeArray[k];

      g.addEdge(v1, v2);
    }
  }
  // //Printing the graph
  // g.printGraph();

  fs.close();

  return 0;
}
