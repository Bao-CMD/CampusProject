#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
  string name;
  int distanceX;
  int distanceY;
};

struct vertex;

struct adjvertex {
  vertex* v;
};

struct vertex{
  string name;
  bool visited = false;
  float distance = 0;
  vertex *pred = NULL;
  vector<adjvertex> adj;
};

class graph {
  public:
  void addEdge(string v1, string v2);
  void addVertex(string v);
  void DijkstraAlgorithm(string start, string end);
  private:
  vector<vertex*> vertices;
};

float distanceY (float y1, float y2);
float distanceX (float x1, float x2);
float diagonalDistance (float x, float y);
float worstCaseDistance(float x, float y);
float averageCaseDistance(float best, float worst);
float distanceToTime (float distance);


#endif
