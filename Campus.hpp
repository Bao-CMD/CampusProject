#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
  string name;
  float distanceY;
  float distanceX;
  node* next;
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
  void addVertex(string name);
  void DijkstraAlgorithm(string start, string end);
  private:
  vector<vertex*> vertices;
};

#endif

float distanceY (float y1, float y2);
float distanceX (float x1, float x2);
float diagonalDistance (float x, float y);
float worstCaseDistance(float x, float y);
float averageCaseDistance(float best, float worst);
float distanceToTime (float distance);

#ifndef HASH_HPP
#define HASH_HPP

class hashtable {
  private:
    static const int tableSize = 31;
    node* table[tableSize];
  public:
    hashtable();
    int hashFunction(string key);
    void addItem(string name, float distY, float distX);
    void printTable(); //Test function
};

#endif
