#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Campus.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  string filename = "";
  if (argc != 2) {
    cout << "Requires 2 arguments" << endl;
  } else {
    filename = argv[1];
  }

  hashtable h;

  // Test 1: adding files one by one manually
  // h.addItem("Benson Earth Sciences", 40.008016, -105.265687);
  // h.addItem("Center for Community", 40.004428, -105.264932);
  // h.addItem("Clare Small Arts and Science", 40.010610, -105.269791);

  //Test 2: inputting files using filestream
  ifstream fs;
  fs.open(filename);
  string line = "";
  string name;
  string y;
  string x;

  if (fs.is_open()) {
    while (fs) {
      getline(fs, line);
      istringstream ss(line);

      getline (ss, name, ',');
      getline (ss, x, ',');
      float dX = stof(x);
      getline (ss, y);
      float dY = stof(y);

      h.addItem(name, dY, dX);
    }
  }
  fs.close();
  h.printTable();

  int indexW = h.hashFunction("Wardenburg Health Center");
  cout << indexW << endl;
  node* location = h.probeFunction(h.tableNode(indexW), "Wardenburg Health Center");
  cout << "made it" << endl;
  cout << location->name << endl;
  cout << location->distanceX << endl;
  cout << location->distanceY << endl;

  //Test 3: using probing function
  // node * n = NULL;
  // int index = hashFunction("Center for Community");

  return 0;
}
