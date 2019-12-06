#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Campus.hpp"

using namespace std;

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
      cout << "index: " << i << endl;
      getline(fs, line);
      istringstream ss(line);

      cout << line << endl;
      getline(ss, name, ',');
      getline(ss, x, ',');
      float dX = stof(x);
      getline(ss, y);
      float dY = stof(y);

      //Adding item to array
      nodeArray[i].addElement(name, dX, dY);
      cout << nodeArray[i].name << endl;
      cout << nodeArray[i].distanceX << endl;
      cout << nodeArray[i].distanceY << endl;
      i++;
      cout << i << endl;
      // }
    }
  }

  //Printing array function
  for (int i = 0; i < 24; i++)
  {
    cout << "Index: " << i << endl;
    cout << "\tString name - " << nodeArray[i].name << endl;
    cout << "\tDistance X - " << nodeArray[i].distanceX << endl;
    cout << "\tDistance Y - " << nodeArray[i].distanceY << endl;
  }

  //Creat graph and add edges


  fs.close();

  return 0;
}
