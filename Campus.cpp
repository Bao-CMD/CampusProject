#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

//Function to calculate and convert latitude degrees to miles
float distanceY (float y1, float y2) {
  float sum = 0.0;
  float milesPerDegree = 69.2;
  sum = y1 + y2;
  float miles = sum / milesPerDegree;
  return miles;
}

//Function to calculate and convert longitude degrees to miles
float distanceX (float x1, float x2) {
  float sum = 0.0;
  float milesPerDegree = 69.2;
  sum = x1 + x2;
  float miles = sum * milesPerDegree;
  return miles;
}

//Function to get the immediate distance between point A and B (best case)
float diagonalDistance(float x, float y) {
  float diagonal = sqr(pow(x,2)+pow(y,2));
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
  float minutes = distance / 15;
  return minutes;
}

//Function to add vertex of CU buildings
void graph::addVertex(string v) {
  //Search for duplicates
  bool found = false;
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name = v) {
      found = true;
    }
  }
  if (found == false) {
    vertex* v = new vertex;
    v->name = v;
    vertices.push_back(v);
  }
}

//Function to add edges between CU  Buildings
void graph::addEdge(string v1, string v2) {
  //Looking for vector of vertices v1
  for (unsigned int i = 0; i < vertices.size(); i++) {
    if (vertices[i]->name == v1) {
      for (unsigned int j = 0; i < vertices.size(); j++) {
        if (vertices[j]->name == v2 && i != j) {
          //Calculating average distance between v1 and v2
          float x =
          //Setting vertices to v1 and v2
          adjvertex av1;
          av1.v = vertices[j];
          vertices[i]->adj.push_back(av1);
          vertices[i]->distance = ;
          //Rendition for bidirection
          adjvertex av2;
          av2.v = vertices[i];
          vertices[j]->adj.push_back(av2);
          vertices[j]->distance = ;
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
    if (vertices[i]->name == start) {
      startV = vertices[i];
    } else if (vertices[i]->name == end) {
      endV = vertices[i];
    }
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
  return endv;
}
