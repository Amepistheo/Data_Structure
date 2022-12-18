#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Graph {

public:
	int n, m, s, index;
	bool visit[1000];
	int d[1000];
	int parent[1000];
	int dist[1000][1000];
	int smallestNode();
	void LoadMatrix(std::string& filename);
	void PrintMatrix();
	Graph();
	void PrintShortestPathWeight(int s);
	int GetSize() { this->n = n; return n; }
	void PrintShortestPath(int s);
	void Sort(int s);
	void Search(int a, int b);
};
#endif
