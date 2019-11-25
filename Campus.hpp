#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct vertex;

struct node {
  string name;
  int distance;
};

struct adjvertex {
  string name;
  bool visited = false;
  int distance = 0;
  vertex *pred = NULL;
  vector<adjvertex> adj;
};

class graph {
public:
  void addEdge(string v1, string v2);
  void addVertex(string v);
  void printInfo();
private:
  vector<vertex*> vertices;
};

#endif
