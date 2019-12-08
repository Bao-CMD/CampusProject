#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#ifndef NODE_H
#define NODE_H

struct node {
  string name;
  float distanceY;
  float distanceX;
  node* next = NULL;
  addElement(string n,float x,float y) {
    name = n;
    distanceY = y;
    distanceX = x;
  }
};

// struct node nodeArray[24];

#endif

#ifndef GRAPH_H
#define GRAPH_H

struct vertex;

struct adjvertex {
  vertex* v;
  float weight; //Time between
};

struct vertex{
  string name;
  bool visited = false;
  float distance = 0; //Distance is the time between vertices
  vertex *pred = NULL;
  vector<adjvertex> adj;
};

class graph {
  private:
  vector<vertex*> vertices;
  public:
  void addEdge(node v1, node v2);
  void addVertex(string name);
  vertex* DijkstraAlgorithm(string start, string end);
  void printGraph();
  void printVertices();
  void printHelper(vertex* end);
  void printPath(string end);
};

#endif

float distanceY (float y1, float y2);
float distanceX (float x1, float x2);
float diagonalDistance (float x, float y);
float worstCaseDistance(float x, float y);
float averageCaseDistance(float best, float worst);
float distanceToTime (float distance);
string time (float fTime);

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
    node* probeFunction(node* curr, string name);
    node* tableNode(int index);
};

#endif
