#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main(void) {
    Graph g;

    string filename;
    getline(cin, filename);

    g.LoadMatrix(filename);
    g.PrintShortestPath(0);

    return 0;
}