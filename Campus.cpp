#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include "Campus.hpp"

using namespace std;

//Function to calculate and convert latitude degrees to miles
float distanceY (float y1, float y2) {
  float diff = 0.0;
  float milesPerDegree = 69.2;
  diff = abs(y1 - y2);
  float miles = diff * milesPerDegree;
  return miles;
}

//Function to calculate and convert longitude degrees to miles
float distanceX (float x1, float x2) {
  float diff = 0.0;
  float milesPerDegree = 69.2;
  diff = abs(x1 - x2);
  float miles = diff * milesPerDegree;
  return miles;
}

//Function to get the immediate distance between point A and B (best case)
float diagonalDistance(float x, float y) {
  //Converting miles to feet
  int feetX = x * 5280;
  cout << feetX << endl;
  int feetY = y * 5280;
  cout << feetY << endl;
  float feetC = sqrt(pow(feetX,2)+pow(feetY,2));
  float diagonal = feetC / 5280;
  return diagonal;
}

//Fumcton to return worst case distance
float worstCaseDistance(float x, float y) {
  return x+y;
}

float averageCaseDistance(float best, float worst) {
  float average = (best+worst)/2;
  return average;
}

//Function to convert distance in miles to walking time using the average
//walk pace of 1 mile every 15 minutes
float distanceToTime (float distance) {
  float minutes = distance * 20;
  return round(minutes);
}

//Function to add vertex of CU buildings
void graph::addVertex(string name) {
  //Search for duplicates
  bool found = false;
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == name) {
      found = true;
    }
  }
  if (found == false) {
    vertex* v = new vertex;
    v->name = name;
    vertices.push_back(v);
  }
}

//Function to add edges between CU  Buildings
void graph::addEdge(node v1, node v2)
{
  //Looking for vector of vertices v1
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == v1.name)
    {
      for (unsigned int j = 0; j < vertices.size(); j++)
      {
        if (vertices[j]->name == v2.name && i != j)
        {
          // cout << "Distance between " << v1.name << " and " << v2.name << endl;
          //Calculating average distance between v1 and v2
          float distX = abs(v1.distanceX - v2.distanceX);
          // cout << "\tX distance in miles: " << distX << endl;
          float distY = abs(v1.distanceY - v2.distanceY);
          // cout << "\tY distance in miles: " << distY << endl;
          float distC = diagonalDistance(distX, distY);
          // cout << "\tDistance: " << distC << endl;
          float avg = averageCaseDistance(distC, distX+distY);
          float time = distanceToTime(avg);
          // cout << "\tTime: " << time << endl;
          //Setting vertices to v1 and v2
          adjvertex av1;
          av1.v = vertices[j];
          av1.weight = time;
          vertices[i]->adj.push_back(av1);
          //Rendition for bidirection
          adjvertex av2;
          av2.v = vertices[i];
          av2.weight = time;
          vertices[j]->adj.push_back(av2);
        }
      }
    }
  }
}

//Function to find the shortest path between two buildings
vertex* graph::DijkstraAlgorithm(string start, string end) {
  vertex* startV;
  vertex* endV;
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == start)
      startV = vertices[i];
    else if (vertices[i]->name == end)
      endV = vertices[i];
  }
  startV->visited = true;
  startV->distance = 0;
  vector<vertex*> solved;
  solved.push_back(startV);
  vertex* parent = NULL;
  while (!endV->visited) {
    vertex* solvedV = NULL;
    int minDistance = 100000;
    for (unsigned int i = 0; i < solved.size(); i++) {
      vertex* s = solved[i];
      for (unsigned int j = 0; j < s->adj.size(); j++) {
        if (!s->adj[j].v->visited) {
          int dist = s->distance + s->adj[j].weight;
          if (dist < minDistance) {
            solvedV = s->adj[j].v;
            minDistance = dist;
            parent = s;
          }
        }
      }
    }
    solvedV->distance = minDistance;
    solvedV->pred = parent;
    solvedV->visited = true;
    solved.push_back(solvedV);
  }
  return endV;
}

void graph::printGraph() {
  for (unsigned int i = 0; i < vertices.size(); i++) {
    cout << vertices[i]->name << ":" << endl;
    for (unsigned int j = 0; j < vertices[i]->adj.size(); j++) {
      cout << "\t" << vertices[i]->adj[j].v->name << endl;
      cout << "\t" << vertices[i]->adj[j].weight << endl;
    }
  }
}

void graph::printVertices() {
  for (unsigned int i = 0; i < vertices.size(); i++) {
    cout << "Vertex: " << i << " ";
    cout << vertices[i]->name << endl;
  }
}

void graph::printHelper(vertex* end) {
  if (end == NULL) return;
  else {
    printHelper(end->pred);
    cout << "Between " << end->name << " and ";
  }
}

void graph::printPath(string end) {
  vertex* last;
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == end) {
      last = vertices[i];
    }
  }
  if (last->pred != NULL) {
    printHelper(last->pred);
  }
  cout << last->name << ":" << endl;
}

//Constructor to initialize hash table size
hashtable::hashtable() {
  for (int i = 0; i < tableSize; i++) {
    table[i] = new node;
    table[i]->name = "empty";
    table[i]->distanceY = 0;
    table[i]->distanceX = 0;
    if (i != tableSize-1) {
      table[i]->next = table[i+1];
    } else {
      table[i]->next = table[0];
    }
  }
}

//Function to add items to the hash table
void hashtable::addItem(string name, float distY, float distX) {
  int index = hashFunction(name);
  if (table[index]->name == "empty") {
    table[index]->name = name;
    table[index]->distanceY = distY;
    table[index]->distanceX = distX;
  } else {
    int count = index;
    while (table[count]->name != "empty") {
      count++;
      count = count % tableSize;
    }
    int newIndex = count % tableSize;
    table[newIndex]->name = name;
    table[newIndex]->distanceY = distY;
    table[newIndex]->distanceX = distX;
  }
}

//Test function to print entire hash table
void hashtable::printTable() {
  for (int i = 0; i < tableSize; i++) {
    cout << "index: " << i << endl;
    cout << "\t" << table[i]->name << endl;
    cout << "\t" << table[i]->distanceY << " - " << table[i]->distanceX << endl;
  }
}

//Function to probe through the hash table
int hashtable::probeFunction (int index, string name) {
  int newIndex = index;
  cout << "enters probe function" << endl;
  if (table[newIndex]->name == name) {
    return newIndex;
  } else {
    if (newIndex == tableSize-1) {
      newIndex = 0;
    } else {
      newIndex++;
    }
  }
  return newIndex;
}

node* hashtable::tableNode(int index) {
  node* temp = table[index];
  return temp;
}

//Hash function
int hashtable::hashFunction (string key) {
  int sum = 0;
  int index;
  for (int i = 0; i < key.length(); i++) {
    sum += (int)key[i];
  }
  index = sum % tableSize;
  return index;
}
