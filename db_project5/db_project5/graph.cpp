#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "graph.h"
using namespace std;	

Graph::Graph() {}
 
void Graph::LoadMatrix(std::string& filename) {
	ifstream fin(filename);
	fin >> n;
	for (int u = 0; u < n; u++) {
		for (int w = 0; w < n; w++) {
			fin >> dist[u][w];
		}
	}
}

void Graph::PrintMatrix() {
	for (int u = 0; u < n; u++) {
		for (int w = 0; w < n; w++) {
			cout << dist[u][w] << ' ';
		}
		cout << endl;
	}
}

int Graph::smallestNode() {
	int min = 999;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] < min && !visit[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void Graph::Sort(int s) {
	for (int i = 0; i < n; i++) {
		d[i] = 0;
		visit[i] = false;
		d[i] = dist[s][i];
	}
	parent[s] = -1;
	d[s] = 0;
	visit[s] = true;
	for (int i = 0; i < n-1; i++) {
		int current = smallestNode();
		visit[current] = true;
		for (int j = 0; j < n; j++) {
			if (!visit[j]) {
				if (d[current] + dist[current][j] < d[j]) {
					d[j] = d[current] + dist[current][j];
					parent[j] = current;
				}
			}
		}
	}
}

void Graph::PrintShortestPathWeight(int s) {
	Sort(s);
	for (int i = 0; i < n; i++) {
		cout << d[i] << endl;
	}
}

void Graph::Search(int a, int b) {
	if (parent[b] == -1) {
		cout << b << " ";
		return;
	}
	else {
		
		Search(a, parent[b]);
		cout << b << " ";
	}
}

void Graph::PrintShortestPath(int s) {
	Sort(s);
	for (int i = 1; i < n; i++) {
		Search(s, i);
		cout << endl;
	}
}
//박윤빈 학생의 도움을 받았습니다.